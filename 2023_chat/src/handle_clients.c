/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:29 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: handle_client function
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <poll.h>
#include <unistd.h>
#include "dprint.h"
#include "chat.h"

static int transmit_message(char *message, struct pollfd *fds, int clients,
                            struct information *info)
{
    char **nicknames;
    int cnt;
    int sender;

    nicknames = info->nickname;
    sender = info->client_action + 2;
    cnt = 2;
    while (cnt < clients + 2) {
        if (cnt != sender && clients > 1) {
            stu_dprintf(fds[cnt].fd,"\033[35;01m[\033[00m\033[33;01m"
                        "%s\033[00m\033[35;01m]\033[00m\t",
                        nicknames[sender - 2]);
            if (stu_strlen(nicknames[sender - 2]) < 6) {
                write(fds[cnt].fd, "\t", 1);
            }
            stu_dprintf(fds[cnt].fd, "%s", message);
        }
        cnt += 1;
    }
    return 0;
}

static void message_hande(struct information *info, char *str,
                   int *nb_client, int *work)
{
    if (stu_strsemicmp("/", str) == 0) {
        *work = command(info);
    } else {
        transmit_message(str, info->fds, *nb_client, info);
    }
}

int handle_clients(struct information *info, char *str,
                   int *nb_client, int *work)
{
    char **nicknames;
    int s_read;

    nicknames = info->nickname;
    s_read = 1;
    info->client_action = 0;
    while (info->client_action < *nb_client) {
        stu_memset(str, 51);
        if (info->fds[info->client_action + 2].revents & POLLHUP) {
            disconnect_client(info->fds,
                              info->client_action, nb_client, nicknames);
        } else if (info->fds[info->client_action + 2].revents & POLLIN) {
            s_read = read(info->fds[info->client_action + 2].fd, str, 200);
            if (s_read > 0) {
                message_hande(info, str, nb_client, work);
            } else {
                disconnect_client(info->fds, info->client_action,
                                  nb_client, nicknames);
            }
        }
        info->client_action = info->client_action + 1;
    }
    return 1;
}
