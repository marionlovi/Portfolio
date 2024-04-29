/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:12 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: add_client function
 */

#include <stdlib.h>
#include <poll.h>
#include "chat.h"

struct pollfd *add_client(struct pollfd *fds, int *limite)
{
    struct pollfd *tampon;

    *limite = *limite + 5;
    tampon = malloc(sizeof(struct pollfd) * (*limite + 2));
    stu_memcpy(tampon, fds, sizeof(struct pollfd) * (*limite - 3));
    free(fds);
    fds = malloc(sizeof(struct pollfd) * (*limite + 2));
    stu_memcpy(fds, tampon, sizeof(struct pollfd) * (*limite - 3));
    free(tampon);
    return fds;
}
