#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include "stu.h"
#include "stu_printf.h"
#include "ls.h"

const struct files_type_row TYPES_TABLE[] = {
    {S_IFCHR, 'l'},
    {S_IFBLK, 'b'},
    {S_IFDIR, 'd'},
    {S_IFLNK, 'c'},
    {S_IFSOCK, 's'}
};

const int TYPES_LEN = sizeof(TYPES_TABLE) / sizeof(TYPES_TABLE[0]);

const struct permissions_row PERM_TABLE[] = {
    {0b000000100, 'r'},
    {0b000000010, 'w'},
    {0b000000001, 'x'},
};

const int PERM_TABLE_LEN = sizeof(PERM_TABLE) / sizeof(PERM_TABLE[0]);

int stock_mode(char *mode_str, struct stat stat_data)
{
    int index;
    int i;
    int j;

    index = 1;
    i = 6;
    while (i >= 0) {
        j = 0;
        while (j < PERM_TABLE_LEN) {
            if (PERM_TABLE[j].name << i & stat_data.st_mode) {
                mode_str[index] = PERM_TABLE[j].symbole;
            }
            index += 1;
            j += 1;
        }
        i -= 3;
    }
    return index;
}

void stock_type(char *mode_str, struct stat stat_data)
{
    int j;
    int file_type_bits;

    j = 0;
    file_type_bits = stat_data.st_mode & S_IFMT;

    while (j < TYPES_LEN) {
        if (file_type_bits == TYPES_TABLE[j].name) {
            mode_str[0] = TYPES_TABLE[j].symbole;
            return;
        }
        j += 1;
    }
}

void print_perm(struct stat stat_data)
{
    int index;
    char *mode_str;

    mode_str = malloc(sizeof(char) * 12);
    stu_memset(mode_str, '-', 10);
    stock_type(mode_str, stat_data);
    index = stock_mode(mode_str, stat_data);
    mode_str[index] = ' ';
    mode_str[index + 1] = '\0';
    write(1, mode_str, 11);
    free(mode_str);
}

