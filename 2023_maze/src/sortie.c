#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "maze.h"

int no_way_out(struct maze *way, struct coordonnee *start)
{
    if (start->position == way->depart) {
        way->out = way->out + 1;
        if (way->out == 5) {
            return 1;
        }
    }
    return 0;
}

int all_side(struct maze *way, struct coordonnee *start)
{
    if (way->buffer[start->position - 1] == 'G') {
        start->column = start->column - 1;
        start->position = start->position - 1;
        return 1;
    }
    if (way->buffer[start->position + 1] == 'G') {
        start->column = start->column + 1;
        start->position = start->position + 1;
        return 1;
    }
    if (way->buffer[start->position - (way->column + 1)] == 'G') {
        start->line = start->line - 1;
        start->position = start->position  - (way->column + 1);
        return 1;
    }
    if (way->buffer[start->position + (way->column + 1)] == 'G') {
        start->line = start->line + 1;
        start->position = start->position + (way->column + 1);
        return 1;
    }
    return 0;
}

int sortie(struct maze *way, struct coordonnee *start)
{
    if (no_way_out(way, start) == 1) {
        return 1;
    } if (way->way_out == 1) {
        return 1;
    } if (all_side(way, start) == 1) {
        return 1;
    } else {
        return 0;
    }
}
