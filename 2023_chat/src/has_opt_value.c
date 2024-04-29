/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-15 - 10:38 +0200
 * 1st author:  tony.yam - tony.yam
 * description: has_opt_value
 */

#include <stddef.h>
#include "dprint.h"
#include "chat.h"

char *has_opt_value(int ac, char **av, char str)
{
    int cmpt1;
    int last_ind;

    cmpt1 = 0;
    while (cmpt1 < ac) {
        last_ind = av[cmpt1][stu_strlen(av[cmpt1]) - 1];
        if (av[cmpt1][0] == '-' && last_ind == str) {
            if (ac > cmpt1 + 1) {
                if (av[cmpt1 + 1][0] != '-') {
                    return (av[cmpt1 + 1]);
                }
            }
        }
        cmpt1 = cmpt1 + 1;
    }
    return (NULL);
}
