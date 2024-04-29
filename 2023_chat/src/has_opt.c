/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-15 - 12:20 +0200
 * 1st author:  tony.yam - tony.yam
 * description: has_opt
 */

#include "dprint.h"
#include "chat.h"

int has_opt(int ac, char **av, char str)
{
    int cmpt1;
    int cmpt2;
    int len_arg;

    cmpt1 = 0;
    while (cmpt1 < ac) {
        if (av[cmpt1][0] == '-') {
            cmpt2 = 1;
            len_arg = stu_strlen(av[cmpt1]);
            while (cmpt2 < len_arg) {
                if (av[cmpt1][cmpt2] == str) {
                    return (1);
                }
                cmpt2 = cmpt2 + 1;
            }
        }
        cmpt1 = cmpt1 + 1;
    }
    return (0);
}
