/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-29 - 13:58 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: create_session function
 */


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <poll.h>
#include "dprint.h"
#include "chat.h"

static int unavailable(int port2, int sock, struct sockaddr_in *addr_and_port)
{
    addr_and_port->sin_port = htons(port2);
    if (bind(sock, (struct sockaddr *) addr_and_port,
             sizeof(addr_and_port))) {
        stu_dprintf(1, "The port is unavailable.\n");
        close(sock);
        return (0);
    }
    return (1);
}

int create_session(int argc, char **argv, char *port)
{
    struct sockaddr_in addr_and_port;
    int sock;
    int check_port;
    int port2;

    port2 = stu_atoi(port);
    check_port = -1;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&addr_and_port, 0, sizeof(addr_and_port));
    addr_and_port.sin_family = AF_INET;
    addr_and_port.sin_addr.s_addr = INADDR_ANY;
    if (has_opt(argc, argv, 'f') == 1 || has_opt(argc, argv, 'p') == 0) {
        while (check_port == -1) {
            addr_and_port.sin_port = htons(port2);
            check_port = bind(sock, (struct sockaddr *) &addr_and_port,
                              sizeof(addr_and_port));
            if (check_port == -1) {
                port2 = port2 + 1;
            }
        }
    } else {
        if (!unavailable(port2, sock, &addr_and_port)){
            return (0);
        }
    }
    stu_dprintf(1, "Le serveur est ouvert sur le port: %d \n", port2);
    return sock;
}
