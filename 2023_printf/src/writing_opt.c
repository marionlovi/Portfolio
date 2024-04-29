#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "stu.h"
#include "stu_printf.h"

int print_prct(int fd, va_list args)
{
    (void) args;

    stu_putchar(fd, '%');
    return 1;
}

int print_caract(int fd, va_list args)
{
    char to_write;

    to_write = va_arg(args, int);
    stu_putchar(fd, to_write);
    return 1;
}

int print_str(int fd, va_list args)
{
    char *to_write;
    int len;

    to_write = va_arg(args, char *);
    len = stu_strlen(to_write);
    write(fd, to_write, len);
    return len;
}
