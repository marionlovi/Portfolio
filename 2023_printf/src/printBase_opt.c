#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "stu.h"
#include "stu_printf.h"

int print_B16(int fd, va_list args)
{
    int to_write;
    int len;

    to_write = va_arg(args, int);
    len = print_base(fd, to_write, "0123456789ABCDEF");
    return len;
}

int print_B2(int fd, va_list args)
{
    int to_write;
    int len;

    to_write = va_arg(args, int);
    len = print_base(fd, to_write, "01");
    return len;
}

int print_B8(int fd, va_list args)
{
    int to_write;
    int len;

    to_write = va_arg(args, int);
    len = print_base(fd, to_write, "01234567");
    return len;
}

int print_B16_ptr(int fd, va_list args)
{
    void *to_write;
    int len;

    to_write = va_arg(args, void *);
    write(fd, "0x", 2);
    len = print_base(fd, (long) to_write, "0123456789abcdef") + 2;
    return len;
}

int print_B10(int fd, va_list args)
{
    int to_write;
    int len;

    to_write = va_arg(args, int);
    len = print_base(fd, to_write, "0123456789");
    return len;
}
