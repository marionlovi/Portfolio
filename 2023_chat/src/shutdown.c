/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-27 - 21:42 +0200
 * 1st author:  tony.yam - tony.yam
 * description: shutdown
 */

#include "chat.h"

int shut_down(struct information *info)
{
    return(end_server(info));
}
