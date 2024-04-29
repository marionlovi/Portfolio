#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include "stu_printf.h"

Test(printBase10, norm_plus)
{
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "base 10 + = %+d", 15);
    cr_assert_stdout_eq_str("base 10 + = +15");
    cr_assert(eq(i32, a, stu_strlen("base 10 + = +15")));
}

Test(printBase10, norm)
{
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "base 10 = %d", 15);
    cr_assert_stdout_eq_str("base 10 = 15");
    cr_assert(eq(i32, a, stu_strlen("base 10 = 15")));
}

Test(printBase16, norm_1)
{
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "base %d de 15 = %x", 16, 15);
    cr_assert_stdout_eq_str("base 16 de 15 = F");
    cr_assert(eq(i32, a, stu_strlen("base 16 de 15 = F")));
}

Test(printBase16, norm_2)
{
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "base %d de 255 = %x", 16, 255);
    cr_assert_stdout_eq_str("base 16 de 255 = FF");
    cr_assert(eq(i32, a, stu_strlen("base 16 de 255 = FF")));
}

Test(printBase16_ptr, norm)
{
    int a;
    void *ptr;
    char *str;

    ptr = &a;
    str = malloc(sizeof(char) * 101);
    snprintf(str, 100, "base %d du ptr = %p", 16, ptr);
    cr_redirect_stdout();
    a = stu_dprintf(1, "base %d du ptr = %p", 16, ptr);
    cr_assert_stdout_eq_str(str);
    cr_assert(eq(i32, a, stu_strlen(str)));
}

Test(printBase8, norm)
{
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "base %d de 255 = %o", 8, 255);
    cr_assert_stdout_eq_str("base 8 de 255 = 377");
    cr_assert(eq(i32, a, stu_strlen("base 8 de 255 = 377")));
}

Test(printBase2, normal1) {
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "base %d de 123 = %b", 2, 123);
    cr_assert_stdout_eq_str("base 2 de 123 = 1111011");
    cr_assert(eq(i32, a, stu_strlen("base 2 de 123 = 1111011")));
}

Test(printBase2, normal_2) {
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "base %d de 5 = %b", 2, 5);
    cr_assert_stdout_eq_str("base 2 de 5 = 101");
    cr_assert(eq(i32, a, stu_strlen("base 2 de 5 = 101")));
}
