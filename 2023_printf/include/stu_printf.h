#ifndef MINI_PRINTF_H_
#define MINI_PRINTF_H_
#include <stdarg.h>

struct multPrint_row {
    char indic;
    int (*write_it)(int fd, va_list args);
};

int print_B16_ptr(int fd, va_list args);
int print_prct(int fd, va_list args);
int stu_dprintf(int fd, const char *pattern, ...);
int print_str(int fd, va_list args);
int print_B10(int fd, va_list args);
int print_B2(int fd, va_list args);
int print_B8(int fd, va_list args);
int print_B16(int fd, va_list args);
int print_caract(int fd, va_list args);

#endif
