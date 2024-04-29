/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-16 - 14:56 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: command file
 */

#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include "dprint.h"
#include "chat.h"

const struct command_table_row COMMAND_TABLE[] = {
    {"/nick ", nick},
    {"/wisp ", wisp},
    {"/kick ", kick},
    {"/shutdown", shut_down},
    {"/list", list},
    {"/help", help},
};

const unsigned int COMMAND_TABLE_LEN =
    sizeof(COMMAND_TABLE) / sizeof(struct command_table_row);

int command(struct information *info)
{
    unsigned int idx;

    idx = 0;
    while (idx < COMMAND_TABLE_LEN) {
        if (!stu_strsemicmp(COMMAND_TABLE[idx].slash_command, info->msg)) {
            return COMMAND_TABLE[idx].fptr(info);
        }
        idx += 1;
    }
    stu_dprintf(info->fds[info->client_action + 2].fd,
                "\033[32;01m"
                "System Error : Unknown Command\n"
                "Use /help to get the command list\n"
                "\033[00m");
    return 1;
}
