#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "stu.h"
#include "stu_printf.h"

const struct multPrint_row PRINT_TABLE[] = {
    {'c', print_caract},
    {'s', print_str},
    {'d', print_B10},
    {'p', print_B16_ptr},
    {'x', print_B16},
    {'b', print_B2},
    {'o', print_B8},
    {'%', print_prct},
};

const int PRINT_LEN = sizeof(PRINT_TABLE) / sizeof(PRINT_TABLE[0]);

int search_d(int fd, const char *pattern, int *written)
{
    int j;

    j = 1;
    while (pattern[j] != '\0') {
        if (pattern[j] != 'd') {
            j += 1;
        } else {
            *written += 1;
            stu_putchar(fd, '+');
            return j;
        }
    }
    return j;
}

int search_pattern(int fd, const char *pattern, int *written, va_list *args)
{
    int i;
    int j;

    j = 1;
    i = 0;
    while (pattern[j] != '\0') {
        i = 0;
        if (pattern[j] == '+') {
            j += search_d(fd, &pattern[j], written);
        }
        while (i < PRINT_LEN) {
            if (PRINT_TABLE[i].indic == pattern[j]) {
                *written += (PRINT_TABLE[i].write_it(fd, *args));
                return j;
            }
            i += 1;
        }
        j += 1;
    }
    return j;
}

int stu_dprintf(int fd, const char *pattern, ...)
{
    va_list args;
    int written;
    unsigned int j;
    unsigned int length;

    j = 0;
    written = 0;
    va_start(args, pattern);
    length = stu_strlen(pattern);
    while (j < length) {
        if (pattern[j] == '%') {
            j += search_pattern(fd, &pattern[j], &written, &args);
        } else {
            stu_putchar(fd, pattern[j]);
            written += 1;
        }
        j += 1;
    }
    va_end(args);
    return written;
}
