/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 12:29 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: help function
 */

#include <poll.h>
#include "dprint.h"
#include "chat.h"

int help(struct information *info)
{
    stu_dprintf(info->fds[info->client_action + 2].fd,
                "\033[32;01mCommand List :\n"
                "/nick [name]: rename user name\n"
                "/wisp [name] [msg]: private message\n"
                "/kick [name]: eject user\n"
                "/shutdown : close serveur\n"
                "/list : list of users\n"
                "/help : displays this message\033[00m\n");
    return (1);
}
