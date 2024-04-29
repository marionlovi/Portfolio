/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:45 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: disconnect client function
 */

#include <poll.h>
#include <string.h>
#include <unistd.h>
#include "chat.h"

void disconnect_client(struct pollfd *fds, int qui,
                       int *nb_client, char **nicknames)
{
    close(fds[qui + 2].fd);
    if (qui != *nb_client) {
        fds[qui + 2].fd = fds[*nb_client + 1].fd;
        fds[qui + 2].events = fds[*nb_client + 1].events;
        *nb_client = *nb_client - 1;
        stu_memset(nicknames[qui], 11);
        stu_memcpy(nicknames[qui], nicknames[*nb_client],
                   strlen(nicknames[*nb_client]));
        stu_memset(nicknames[*nb_client], 11);
    }
}
