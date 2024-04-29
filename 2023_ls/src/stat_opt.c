#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include "stu.h"
#include "stu_printf.h"
#include "ls.h"

int nblen(int nb)
{
    int i;
    int j;

    j = 0;
    i = nb;
    while (i >= 10) {
        j = j + 1;
        i = i / 10;
    }
    j += 1;
    return j;
}

int print_it_all(int nb)
{
    if ((nb / 10) > 0) {
        return 0;
    } else {
        return 1;
    }
}

int format_all(struct stat *stat_data, struct tm *time, struct options opts)
{
    int size;

    time->tm_mon += 1;
    if (opts.opt_h == 1) {
        size = nblen(stat_data->st_size);
        if (size <= 3) {
            return 0;
        } else if (size == 4) {
            stat_data->st_size /= 100;
            return 1;
        }
        stat_data->st_size /= stu_pow(10, size - 2);
        return 2;
    }
    return 0;
}

void print_date(struct tm time)
{
    stu_dprintf(1," %d-", time.tm_year + 1900);
    if (time.tm_mon < 10) {
        tc_putchar('0');
    }
    stu_dprintf(1,"%d-", time.tm_mon);
    if (time.tm_mday < 10) {
        tc_putchar('0');
    }
    stu_dprintf(1,"%d ", time.tm_mday);
}

void print_time(struct tm time)
{
    if (time.tm_hour < 10) {
        tc_putchar('0');
    }
    stu_dprintf(1," %d:", time.tm_hour + 1);
    if (time.tm_min < 10) {
        tc_putchar('0');
    }
    stu_dprintf(1,"%d", time.tm_min);
}

void print_medium_size(struct stat stat_data, struct tm time, char *file)
{
    int nb;

    nb = stat_data.st_size % 10;
    stu_dprintf(1,"%d %d %d ",
                stat_data.st_nlink, stat_data.st_uid,stat_data.st_gid);
    if (stat_data.st_size == 0) {
        tc_putchar('0');
    } else if (nb != 0) {
        stu_dprintf(1," %d,%dK", stat_data.st_size / 10, nb);
    } else {
        stu_dprintf(1," %d,0K ", stat_data.st_size / 10);
    }
    print_date(time);
    print_time(time);
    stu_dprintf(1," %s\n", file);
}

void print_big_size(struct stat stat_data, struct tm time, char *file)
{
    stu_dprintf(1,"%d %d %d %dK ",
                stat_data.st_nlink, stat_data.st_uid,
                stat_data.st_gid, stat_data.st_size);
    print_date(time);
    print_time(time);
    stu_dprintf(1," %s\n", file);
}

void print_all(struct stat stat_data, struct tm time,
               char *file, struct options opts)
{
    int format;

    format = format_all(&stat_data, &time, opts);
    if (format == 0) {
        stu_dprintf(1,"%d %d %d %d %d",
                    stat_data.st_nlink, stat_data.st_uid,
                    stat_data.st_gid, stat_data.st_size);
        if (stat_data.st_size == 0) {
            tc_putchar('0');
        }
        print_date(time);
        print_time(time);
        stu_dprintf(1," %s\n", file);
        return;
    } else if (format == 1) {
        print_medium_size(stat_data, time, file);
        return;
    }
    print_big_size(stat_data, time, file);
}

void print_info_files(char *path, char **files, struct options opts)
{
    int i;
    struct stat stat_data;
    struct tm time;
    char *file;

    i = 0;
    while (files[i] != NULL) {
        if (stu_strcmp(path, files[i]) != 0) {
            file = malloc(sizeof(char) * (stu_strlen(path)
                                          + 1 + stu_strlen(files[i])));
            file = stu_strcpy(file, path);
            file = stu_strcat(file, files[i]);
        } else {
            file = malloc(sizeof(char) * (stu_strlen(path)));
            file = stu_strcpy(file,files[i]);
        }
        if (stat(file, &stat_data) == -1) {
            i = i;
        }
        print_perm(stat_data);
        time = *gmtime(&stat_data.st_mtime);
        print_all(stat_data, time, files[i], opts);
        i += 1;
        free(file);
    }
}
