#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "maze.h"

void checksideE(struct maze *way, struct coordonnee *start)
{
    if (start->propa[start->position + 1] < start->distance &&
        start->propa[start->position + 1] != 0) {
        start->distance = start->propa[start->position + 1];
    }
    if (start->propa[start->position + (way->column + 1)] < start->distance &&
        start->propa[start->position + (way->column + 1)] != 0) {
        start->distance = start->propa[start->position + (way->column + 1)];
    }
    if (start->propa[start->position - (way->column + 1)] < start->distance &&
        start->propa[start->position - (way->column + 1)] != 0) {
        start->distance =  start->propa[start->position - (way->column + 1)];
    }
    start->distance =  start->distance + 1;
    start->propa[start->position ] = start->distance;
    if (way->buffer[start->position - (way->column + 1)] != '#') {
        goNorth(way, start);
    }
}

void goEast(struct maze *way, struct coordonnee *start)
{
    while (way->buffer[start->position + 1] != '#' &&
           (way->buffer[start->position] != 'G')) {
        way->way_out = sortie(way, start);
        if (way->way_out == 1) {
            return;
        } else {
            way->buffer[start->position] = ' ';
            start->j = start->j + 1;
            start->position = start->position + 1;
            start->column = start->column + 1;
            checksideE(way, start);
        }
    }
    if (way->buffer[start->position + 1] == '#') {
        if (way->buffer[start->position - (way->column + 1)] == '#') {
            goSouth(way, start);
        } else {
            goNorth(way, start);
        }
    }
}
