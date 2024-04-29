#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "stu.h"
#include "stu_printf.h"
#include "ls.h"

void print_files(char **files)
{
    int i;

    i = 0;
    while (files[i] != NULL) {
        write(1, files[i], stu_strlen(files[i]));
        tc_putchar(' ');
        i++;
    }
    tc_putchar('\n');
}

int count_files(char *path)
{
    int i;
    DIR *dir;
    struct dirent *current_entry;

    i = 0;
    dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }
    current_entry = readdir(dir);
    while (current_entry) {
        if (current_entry->d_name[0] != '.') {
            i += 1;
        }
        current_entry = readdir(dir);
    }
    closedir(dir);
    return i;
}

char **handle_file(char *path)
{
    struct stat stat_data;
    char **file;

    if (stat(path, &stat_data) == -1) {
        stu_dprintf(1, "./ls: %s: %s\n", path, strerror(errno));
        return NULL;
    }
    file = malloc(sizeof(char *) * 2);
    file[0] = malloc(stu_strlen(path));
    stu_strcpy(file[0], path);
    file[1] = NULL;
    return file;
}

char **store_files(char *path)
{
    int i;
    DIR *dir;
    struct dirent *current_entry;
    char **files;

    dir = opendir(path);
    if (!dir) {
        files = handle_file(path);
    } else {
        i = count_files(path);
        files = malloc(sizeof(char*) * (i + 1));
        i = 0;
        current_entry = readdir(dir);
        while (current_entry) {
            if (current_entry->d_name[0] != '.') {
                files[i] = malloc(stu_strlen(current_entry->d_name) + 1);
                stu_strcpy(files[i], current_entry->d_name);
                i++;
            }
            current_entry = readdir(dir);
        }
        files[i] = NULL;
    }
    closedir(dir);
    return files;
}

int count_all_files(char *path)
{
    int i;
    DIR *dir;
    struct dirent *current_entry;

    i = 0;
    dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }
    current_entry = readdir(dir);
    while (current_entry) {
        i += 1;
        current_entry = readdir(dir);
    }
    closedir(dir);
    return i;
}

char **store_all_files(char *path)
{
    int i;
    DIR *dir;
    struct dirent *current_entry;
    char **files;

    dir = opendir(path);
    if (!dir) {
        files = handle_file(path);
    }
    i = count_all_files(path);
    files = malloc(sizeof(char*) * (i + 1));
    i = 0;
    current_entry = readdir(dir);
    while (current_entry) {
        files[i] = malloc(stu_strlen(current_entry->d_name) + 1);
        stu_strcpy(files[i], current_entry->d_name);
        i++;
        current_entry = readdir(dir);
    }
    files[i] = NULL;
    closedir(dir);
    return files;
}

void call_fction(char *path, struct options opts)
{
    char **files;
    int i;

    i = 0;
    if (opts.opt_a == 1) {
        files = store_all_files(path);
    } else {
        files = store_files(path);
    }
    if (files != NULL) {
        strtab_sort(files);
        if (opts.opt_l != 1) {
            print_files(files);
        } else {
            print_info_files(path, files, opts);
        }
        while (files[i] != NULL) {
            free(files[i]);
            i += 1;
        }
    free(files);
    }
}

char *get_path(char *path_yet)
{
    char *real_path;
    int len;

    len = stu_strlen(path_yet);
    if (path_yet[len - 1] != '/') {
        real_path = malloc(sizeof(char) * (len + 2));
        stu_strcpy(real_path, path_yet);
        stu_strcat(real_path, "/");
    } else {
        real_path = malloc(sizeof(char) * (len + 1));
        stu_strcpy(real_path, path_yet);
    }
    return real_path;
}

void start_ls(int ac, char **target, struct options opts)
{
    int i;
    char *file;

    i = 1;
    if (ac < 2) {
        call_fction("./", opts);
    } else if (ac == 2) {
        file = get_path(target[i]);
        call_fction(file, opts);
        free(file);
    } else {
        while (i < ac) {
            write(1, target[i], stu_strlen(target[i]));
            file = get_path(target[i]);
            write (1, ":\n", 2);
            call_fction(file, opts);
            free(file);
            if (i != ac - 1) {
                tc_putchar('\n');
            }
            i += 1;
        }
    }
}
