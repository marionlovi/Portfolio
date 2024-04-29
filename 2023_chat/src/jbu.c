/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:56 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: jbu function
 */

#include "chat.h"

int just_be_unique(int nb_client, char **nicknames, char *nick_potentiel)
{
    int i;

    i = 0;
    while (i < nb_client) {
        if (stu_strcmp(nicknames[i], nick_potentiel) == 0) {
            return 1;
        } else {
            i += 1;
        }
    }
    return 0;
}
