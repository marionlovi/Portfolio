/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:24 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: create_nicknames_list function
 */

#include <stdlib.h>

char **create_nicknames_list(int nb, char **nicknames)
{
    int i;

    i = 0;
    while (i < nb) {
        nicknames[i] = malloc(sizeof(char) * 11);
        i += 1;
    }
    return nicknames;
}
