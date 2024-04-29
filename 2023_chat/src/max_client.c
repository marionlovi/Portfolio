/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:48 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: max_client function
 */

#include <sys/socket.h>
#include <poll.h>
#include <unistd.h>
#include "dprint.h"
#include "chat.h"

void max_client(int sock)
{
    int new_conn;

    new_conn = accept(sock, NULL, 0);
    stu_dprintf(new_conn, "Maximum client capacity reached, come back later\n");
    close(new_conn);
}
