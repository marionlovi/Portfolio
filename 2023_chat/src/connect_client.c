/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:51 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: connect_client function
 */

#include <sys/socket.h>
#include <poll.h>
#include <stddef.h>
#include "chat.h"

void connect_client(struct pollfd *fds, int *nb_client,
                    int sock, char **nicknames)
{
    int new_conn;

    new_conn = accept(sock, NULL, 0);
    fds[*nb_client + 2].fd = new_conn;
    fds[*nb_client + 2].events = POLLIN;
    fds[*nb_client + 2].revents = 0;
    if (set_nicknames(*nb_client, new_conn, nicknames) == 0) {
        *nb_client = *nb_client + 1;
    }
}
