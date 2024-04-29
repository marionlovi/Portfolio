#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "stu.h"
#include "stu_printf.h"
#include "ls.h"

const struct ls_opt_row LS_TABLE[] = {
    {'a', stock_opt_a},
    {'c', stock_opt_c},
    {'l', stock_opt_l},
    {'h', stock_opt_h},
};

void stock_opt_a(struct options *opts)
{
    opts->opt_a = 1;
}

void stock_opt_c(struct options *opts)
{
    opts->opt_c = 1;
}

void stock_opt_l(struct options *opts)
{
    opts->opt_l = 1;
}

void stock_opt_h(struct options *opts)
{
    opts->opt_h = 1;
}

const int LS_LEN = sizeof(LS_TABLE) / sizeof(LS_TABLE[0]);

int search_opt(char opt_to_find, struct options *opts)
{
    int table_idx;

    table_idx = 0;
    while (table_idx < LS_LEN) {
        if (LS_TABLE[table_idx].indic == opt_to_find) {
            LS_TABLE[table_idx].stock_opt(opts);
            return 1;
        }
        table_idx += 1;
    }
    stu_dprintf(1,"options %c inexistante\n", opt_to_find);
    return 0;
}

void ls_opt(int ac, char **av)
{
    int arg_idx;
    int i;
    struct options opts;
    void *ptr_opts;

    ptr_opts = &opts;
    stu_memset(ptr_opts, 0, 4);
    arg_idx = 1;
    while (arg_idx < ac) {
        i = 1;
        if (av[arg_idx][0] == '-') {
            while (av[arg_idx][i] != '\0') {
                if (search_opt(av[arg_idx][i], &opts) == 0) {
                    return;
                }
                i += 1;
            }
            stu_memmove(&av[arg_idx], &av[arg_idx + 1],
                        sizeof(char *) * (ac - arg_idx));
            ac -= 1;
            arg_idx -= 1;
        }
        arg_idx += 1;
    }
    start_ls(ac, av, opts);
}
