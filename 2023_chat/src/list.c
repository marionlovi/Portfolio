/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 12:28 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: list function
 */

#include <poll.h>
#include "dprint.h"
#include "chat.h"

int list(struct information *info)
{
    int cnt;

    cnt = 0;
    stu_dprintf(info->fds[info->client_action + 2].fd,
                "\033[32;01mUser List :\033[00m\n");
    while (cnt != info->nb_client) {
        stu_dprintf(info->fds[info->client_action + 2].fd,
                    "\033[33;01m%s\033[00m\n", info->nickname[cnt]);
        cnt = cnt + 1;
    }
    return (1);
}
