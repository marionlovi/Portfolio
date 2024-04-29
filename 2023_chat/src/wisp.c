/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-27 - 21:41 +0200
 * 1st author:  tony.yam - tony.yam
 * description: wisp
 */

#include <poll.h>
#include <stdlib.h>
#include <unistd.h>
#include "dprint.h"
#include "chat.h"

static void get_target(struct information *info, char *cible)
{
    int cnt;

    cnt = 0;
    while (info->msg[6 + cnt] != ' ' && info->msg[6 + cnt] != '\0') {
        cnt = cnt + 1;
    }
    if (cnt >= 10) {
        stu_memcpy(cible, &info->msg[6], 10);
    } else {
        stu_memcpy(cible, &info->msg[6], cnt);
    }
}

static int wisp_loop(struct information *info, int cnt, char *cible, int strt)
{
    if (!stu_strcmp(info->nickname[cnt], cible)) {
        stu_dprintf(info->fds[cnt + 2].fd,"\033[31;01mPv\033[00m\033[33;01m"
                    "\033[35;01m[\033[00m\033[33;01m"
                    "%s\033[00m\033[35;01m]\033[00m\t",
                    info->nickname[info->client_action]);
        if (stu_strlen(info->nickname[info->client_action]) < 4) {
            write(info->fds[cnt + 2].fd, "\t", 1);
        }
        stu_dprintf(info->fds[cnt + 2].fd, "%s",
                    &info->msg[strt + stu_strlen(info->nickname[cnt]) + 1]);
        return (1);
    }
    return (0);
}

int wisp(struct information *info)
{
    char *cible;
    int strt;
    int cnt;
    int reussite;

    strt = 6;
    reussite = 0;
    cnt = 0;
    cible = malloc(sizeof(char) * 11);
    stu_memset(cible, 11);
    get_target(info, cible);
    while (cnt < info->nb_client) {
        if (wisp_loop(info, cnt, cible, strt)) {
            reussite = 1;
        }
        cnt = cnt + 1;
    }
    if (!reussite) {
        stu_dprintf(info->fds[info->client_action + 2].fd,
                    "\033[32;01m"
                    "System Error : Unknown Target \\ No message \n \033[00m");
    }
    free(cible);
    return (1);
}
