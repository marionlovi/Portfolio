#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "maze.h"

void parcours_start(struct maze *way, struct coordonnee *start)
{
    start->position = (start->column - 1) + ((start->line - 1)
                                             * way->column) + (start->line - 1);
    start->propa[start->position] = 1;
    if (start->line == 1) {
        way->depart = start->position + (way->column + 1);
        goSouth(way, start);
    }
    if (start->line == way->line) {
        way->depart = start->position - (way->column + 1);
        goNorth(way, start);
    }
    if (start->column == 1) {
        way->depart = start->position + 1;
        goEast(way, start);
    }
    if (start->column == way->column) {
        way->depart = start->position - 1;
        goWest(way, start);
    }
}

void LineCheck(struct maze *way, struct coordonnee *start)
{
    int i;

    i = 0;
    while (way->buffer[i] != '\0') {
        if (way->buffer[i] != '\n') {
            way->column = way->column + 1;
        } else if (way->buffer[i] == '\n' && way->buffer[i + 1] != '\0') {
            way->line = way->line + 1;
            way->column = 0;
        }
        if (way->buffer[i] == 'S') {
            start->line = way->line;
            start->column = way->column;
        }
        i = i + 1;
    }
}

void final_malloc(struct maze *way, struct coordonnee *start,
                  char **av, int size_malloc)
{
    int fd;
    int size_read;

    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        return;
    }
    way->buffer = malloc(sizeof(char) * size_malloc + 1);
    start->propa = malloc(sizeof(int) * (size_malloc + 1));
    if (way->buffer == NULL && start->propa == NULL) {
        return;
    }
    size_read = read(fd, way->buffer, sizeof(char) * size_malloc);
    way->buffer[size_read] = '\0';
    start->propa[size_read] = '\0';
    while (size_malloc != 0) {
        start->propa[size_malloc] = 0;
        size_malloc = size_malloc - 1;
    }
    close(fd);
}

void read_malloc(struct maze *way, struct coordonnee *start, char **av)
{
    int fd;
    int size_read;
    int size_malloc;
    char *temp_malloc;

    fd = 0;
    size_read = 0;
    size_malloc = 0;
    temp_malloc = malloc(sizeof(char) * 10000);
    if (temp_malloc == NULL) {
        return;
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        return;
    }
    while ((size_read = read(fd, temp_malloc, sizeof(char) * 10000)) > 0) {
        size_malloc = size_malloc + size_read;
    }
    free(temp_malloc);
    close(fd);
    final_malloc(way, start, av, size_malloc);
}

void print_way(struct maze *way, struct coordonnee *start)
{
    int i;

    i = 0;
    while (way->buffer[i] != '\0') {
        if (start->propa[i] > 0) {
            tc_putchar(start->propa[i] % 10 + '0');
        } else {
            tc_putchar(way->buffer[i]);
        }
        i = i + 1;
    }
    tc_putchar('\n');
}

void print_firstway(struct maze *way)
{
    int i;

    i = 0;
    while (way->buffer[i] != '\0') {
        tc_putchar(way->buffer[i]);
        i = i + 1;
    }
    tc_putchar('\n');
}

void call_fct(char **av, struct maze *way,struct coordonnee *start)
{
    read_malloc(way, start, av);
    LineCheck(way, start);
    write(1, "\ntaille : (", 11);
    print_base10(way->line);
    print_base10(way->column);
    write(1,")\n", 2);
    parcours_start(way, start);
    print_firstway(way);
    write(1, "\nnombres de pas totaux : ", 25);
    print_base10(start->j);
    write(1, "\nnombres de pas optimal : ", 26);
    print_base10(start->distance);
    tc_putchar('\n');
    if (way->out >= 5) {
        write(1, "\nPas d'issue possibe\n",21);
    } else {
        print_way(way, start);
    }
}

int main(int ac, char **av)
{
    struct coordonnee start;
    struct maze way;

    start.j = 0;
    start.distance = 0;
    way.line = 1;
    way.column = 0;
    way.out = 0;
    way.way_out = 0;
    if (ac > 1) {
        call_fct(av, &way, &start);
        free(way.buffer);
        free(start.propa);
    }
}
