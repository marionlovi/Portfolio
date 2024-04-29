/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-16 - 16:29 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: memcpy function
 */

#include "chat.h"

void *stu_memcpy(void *dest, const void *src, unsigned int n)
{
    const char *tamp_src;
    char *tamp_dest;
    unsigned int j;

    tamp_src = src;
    tamp_dest = dest;
    j = 0;
    while (j != n) {
        tamp_dest[j] = tamp_src[j];
        j = j + 1;
    }
    return dest;
}
