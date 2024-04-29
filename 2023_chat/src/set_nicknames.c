/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:53 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: set_nicknames function
 */

#include <poll.h>
#include <stdlib.h>
#include <unistd.h>
#include "dprint.h"
#include "chat.h"

static int condition(char **tampon, int nb_client,
                      int fd_client, char **nicknames)
{

    *tampon = forbidden_char(*tampon);
    if (just_be_unique(nb_client, nicknames, *tampon) == 0) {
        nicknames[nb_client] = stu_memcpy(nicknames[nb_client], *tampon, 11);
        stu_dprintf(1, "new pseudo = %s\n", nicknames[nb_client]);
        return (1);
    } else {
        stu_dprintf(fd_client, "\033[32;01mUsername already used,"
                    " choose another one\033[00m\n");
    }
    return (0);
}

static void print_it(int fd_client)
{
    stu_dprintf(1, "\033[32;01mChoose a username\033[00m\n");
    stu_dprintf(fd_client, "\033[32;01mChoose a username\033[00m\n");
}

int set_nicknames(int nb_client, int fd_client, char **nicknames)
{
    char *tampon;
    int size_read;
    int unique;

    unique = 0;
    tampon = malloc(sizeof(char) * 11);
    print_it(fd_client);
    while (unique == 0) {
        size_read = read(fd_client, tampon, 10);
        if (size_read != 0 ) {
            if (tampon[size_read - 1] == '\n') {
                size_read = size_read - 1;
            }
            tampon[size_read] = '\0';
            if (condition(&tampon, nb_client, fd_client, nicknames)) {
                unique = 1;
            }
        } else {
            close(fd_client);
            free(tampon);
            return (1);
        }
    }
    free(tampon);
    return (0);
}
