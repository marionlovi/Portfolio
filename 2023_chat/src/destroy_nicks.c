/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 10:34 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: destroy_nicks function
 */

#include <stdlib.h>

void destroy_nicks(char **nicknames, int size)
{
    int i;

    i = 0;
    while (i < size) {
        free(nicknames[i]);
        i += 1;
    }
}
