/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-19 - 16:23 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: end_server function
 */

#include <poll.h>
#include <stdlib.h>
#include <unistd.h>
#include "dprint.h"
#include "chat.h"

int end_server(struct information *info)
{
    destroy_nicks(info->nickname, info->limite);
    while (info->nb_client) {
        stu_dprintf(info->fds[info->nb_client + 1].fd,
                    "\033[32;01mServer has been shutdown\033[00m\n");
        close(info->fds[info->nb_client + 1].fd);
        info->nb_client = info->nb_client - 1;
    }
    free(info->nickname);
    return (0);
}
