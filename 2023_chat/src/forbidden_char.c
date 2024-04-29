/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_caht
 * created on:  2024-04-29 - 13:55 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: forbidden_char
 */

#include <stdlib.h>
#include "chat.h"

char *forbidden_char(char *nick)
{
    char *tampon;
    int forbiden;
    int idx;

    idx = 0;
    tampon = malloc(sizeof(char) * 11);
    forbiden = 0;
    while (nick[idx + forbiden] != '\0') {
        if (nick[idx + forbiden] == ' ') {
            forbiden += 1;
        }
        tampon[idx] = nick[idx + forbiden];
        idx += 1;
    }
    while (idx <= 10) {
        tampon[idx] = '\0';
        idx += 1;
    }
    free(nick);
    return tampon;
}
