/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-27 - 21:42 +0200
 * 1st author:  tony.yam - tony.yam
 * description: kick
 */


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <poll.h>
#include "dprint.h"
#include "chat.h"

int kick(struct information *info)
{
    int i;
    int size;

    i = 0;
    size = stu_strlen(info->msg);
    if (info->msg[size - 1] == '\n') {
        info->msg[size - 1] = '\0';
    }
    while (i < info->nb_client) {
        if (stu_strcmp(info->nickname[i], &info->msg[6]) == 0) {
            stu_dprintf(info->fds[i + 2].fd, "%s vous a exclus \n",
                        info->nickname[info->client_action]);
            disconnect_client(info->fds, i,
                              &info->nb_client, info->nickname);
            return 1;
        }
        i += 1;
    }
    stu_dprintf(info->fds[info->client_action + 2].fd, "\033[32;01m"
                "System Error : Unknown Target\n"
                "\033[00m");
    return 1;
}
