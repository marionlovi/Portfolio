/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-27 - 21:39 +0200
 * 1st author:  tony.yam - tony.yam
 * description: nick
 */

#include "dprint.h"
#include "chat.h"


static void changement(struct information *info, int taille, int strt)
{
    stu_memset(info->nickname[info->client_action], 10);
    if (taille >= 10) {
        stu_memcpy(info->nickname[info->client_action], &info->msg[strt], 10);
        info->nickname[info->client_action][10] = '\0';
    } else {
        stu_memcpy(info->nickname[info->client_action], &info->msg[strt],
                   taille + 1);
    }
}

int nick(struct information *info)
{
    int strt;
    int taille;

    strt = 6;
    taille = 0;
    while (info->msg[strt + taille] != '\0' &&
           info->msg[strt + taille] != ' ') {
        taille = taille + 1;
    }
    if (info->msg[strt + taille - 1] == '\n') {
        info->msg[strt + taille - 1] = '\0';
    }
    changement(info, taille - 1, strt);
    return (1);
}
