/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_lab_poll
 * created on:  2024-04-10 - 16:37 +0200
 * 1st author:  tony.yam - tony.yam
 * description: multi_echo
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <poll.h>
#include "dprint.h"
#include "chat.h"

static int work_hard(int argc, char **argv, struct information *info, int *work)
{
    poll(info->fds, info->nb_client + 2, -1);
    if (info->fds[0].revents & POLLIN && info->nb_client < info->limite) {
        connect_client(info->fds, &info->nb_client,
                       info->fds[0].fd, info->nickname);
    } else if (info->fds[0].revents & POLLIN &&
               info->nb_client >= info->limite) {
        if (has_opt(argc, argv, 'l') == 0) {
            info->fds = add_client(info->fds, &info->limite);
            info->nickname = add_nicknames(info->limite, info->nickname);
            connect_client(info->fds, &info->nb_client,
                           info->fds[0].fd, info->nickname);
        } else {
            max_client(info->fds[0].fd);
        }
    }
    if (info->fds[1].revents & POLLIN && read(info->fds[1].fd,
                                              info->msg, 200) == 0) {
        *work = end_server(info);
    } else {
        handle_clients(info, info->msg, &info->nb_client, work);
    }
    return (0);
}

static int connect_and_write(int argc, char **argv,
                             struct information *info, int limite)
{
    int work;

    info->limite = limite;
    info->nickname = malloc(sizeof(char *) * info->limite);
    info->msg = malloc(sizeof(char) * 201);
    if (!info->nickname || !info->msg) {
        return (1);
    }
    info->nickname = create_nicknames_list(info->limite, info->nickname);
    stu_memset(info->msg, 201);
    info->nb_client = 0;
    work = 1;
    while (work) {
        work_hard(argc, argv, info, &work);
    }
    free(info->msg);
    free(info->fds);
    free(info);
    return (0);
}

static int initialisation(int argc, char **argv, char *client_limit, char *port)
{
    struct pollfd *fds;
    struct information *info;
    int sock;
    int result;

    fds = malloc(sizeof(struct pollfd) * (stu_atoi(client_limit) + 2));
    sock = create_session(argc, argv, port);
    if (!sock || !fds) {
        return (1);
    }
    listen(sock, 5);
    fds[0].fd = sock;
    fds[0].events = POLLIN;
    fds[0].revents = 0;
    fds[1].fd = 0;
    fds[1].events = POLLIN;
    fds[1].revents = 0;
    info = malloc(sizeof(struct information));
    if (!info) {
        return (1);
    }
    info->fds = fds;
    result = connect_and_write(argc, argv, info, stu_atoi(client_limit));
    close(sock);
    return (result);
}

int main(int argc, char **argv)
{
    char *value_l;
    char *value_p;

    value_l = has_opt_value(argc, argv, 'l');
    value_p = has_opt_value(argc, argv, 'p');
    if ((value_l != NULL && stu_atoi(value_l) == 0) ||
        (value_l == NULL && has_opt(argc, argv, 'l'))) {
        stu_dprintf(1, "Invalid value for 'l' option\n");
        return (0);
    }
    if ((value_p != NULL && stu_atoi(value_p) == 0) ||
        (value_p == NULL && has_opt(argc, argv, 'p'))) {
        stu_dprintf(1, "Invalid value for 'p' option\n");
        return (0);
    } else if (!has_opt(argc, argv, 'p')) {
        value_p = "2030";
    }
    if  (!has_opt(argc, argv, 'l')) {
        value_l = "2";
    }
    return (initialisation(argc, argv, value_l, value_p));
}
