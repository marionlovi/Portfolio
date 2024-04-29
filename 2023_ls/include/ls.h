#ifndef LS_H_
#define LS_H_
#include <sys/stat.h>
#include <stdarg.h>

struct options {
    int opt_a;
    int opt_c;
    int opt_l;
    int opt_h;
};

struct files_type_row {
    int name;
    char symbole;
};

struct permissions_row {
    int name;
    char symbole;
};

struct ls_opt_row {
    char indic;
    void (*stock_opt)(struct options *opts);
};

void print_perm(struct stat stat_data);
void stock_opt_a(struct options *opts);
void stock_opt_c(struct options *opts);
void stock_opt_l(struct options *opts);
void stock_opt_h(struct options *opts);
void start_ls(int ac, char **target, struct options opts);
void strtab_sort(char **strtab);
void ls_opt(int ac, char **av);
void print_info_files(char *path, char **files, struct options opts);
int search_opt(char opt_to_find, struct options *opts);
int count_files(char *path);
int count_all_files(char *path);
char **store_files(char *path);
char **store_all_files(char *path);

#endif
