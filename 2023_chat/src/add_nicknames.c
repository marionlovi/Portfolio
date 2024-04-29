/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:18 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: add_nicknames function
 */

#include <stdlib.h>
#include "chat.h"

static void cpy_all(char **dest, char **src, int taille)
{
    int i;

    i = 0;
    while (i < taille) {
        stu_memcpy(dest[i], src[i], 11);
        i += 1;
    }
}

char **add_nicknames(int limite,char **nicknames)
{
     char **nick_tamp;

     nick_tamp = malloc(sizeof(char *) * limite);
     nick_tamp = create_nicknames_list(limite, nick_tamp);
     cpy_all(nick_tamp, nicknames, limite - 5);
     destroy_nicks(nicknames, limite - 5);
     free(nicknames);
     nicknames =  malloc(sizeof(char *) * limite);
     nicknames = create_nicknames_list(limite, nicknames);
     cpy_all(nicknames, nick_tamp, limite - 5);
     destroy_nicks(nick_tamp, limite);
     free(nick_tamp);
     return nicknames;
}
