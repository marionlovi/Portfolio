#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "maze.h"

void checksideN(struct maze *way, struct coordonnee *start)
{
    if (start->propa[start->position - (way->column + 1)] < start->distance &&
        start->propa[start->position - (way->column + 1)] != 0) {
        start->distance = start->propa[start->position - (way->column + 1)];
    }
    if (start->propa[start->position + 1] < start->distance &&
        start->propa[start->position + 1] != 0) {
        start->distance = start->propa[start->position + 1];
    }
    if (start->propa[start->position - 1] < start->distance
        && start->propa[start->position - 1] != 0) {
        start->distance = start->propa[start->position - 1];
    }
    start->distance =  start->distance + 1;
    start->propa[start->position ] = start->distance;
    if (way->buffer[start->position - 1] != '#') {
        goWest(way, start);
    }
}

void goNorth(struct maze *way, struct coordonnee *start)
{
    while (way->buffer[start->position -
                       (way->column + 1)] != '#' &&
           (way->buffer[start->position] != 'G')) {
        way->way_out = sortie(way, start);
        if (way->way_out == 1) {
            return;
        } else {
            way->buffer[start->position] = ' ';
            start->j = start->j + 1;
            start->line = start->line - 1;
            start->position = start->position - (way->column + 1);
            checksideN(way, start);
        }
    }
    if (way->buffer[start->position  - (way->column + 1)] == '#') {
        if (way->buffer[start->position - 1] == '#') {
            goEast(way, start);
        } else {
            goWest(way, start);
        }
    }
}
