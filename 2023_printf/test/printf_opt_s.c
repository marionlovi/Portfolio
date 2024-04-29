#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include "stu_printf.h"

Test(print_str, string)
{
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "to%s", "to");
    cr_assert_stdout_eq_str("toto");
    cr_assert(eq(i32, a, 4));
}

Test(print_str, vide) {
    int a;
    cr_redirect_stdout();
    a = stu_dprintf(1, "%s", "");
    cr_assert_stdout_eq_str("");
    cr_assert(eq(i32, a, 0));
}

Test(print_str, char_loin) {
    int a;
    cr_redirect_stdout();
    a = stu_dprintf(1, "% azers", "toto");
    cr_assert_stdout_eq_str("toto");
    cr_assert(eq(i32, a, 4));
}

Test(print_str, multi_char) {
    int a;
    cr_redirect_stdout();
    a = stu_dprintf(1, "%   s%aaaas%zzzzs%eeees%rrrs", "si ","je ","ne ","m'abuse",".\n The end.");
    cr_assert_stdout_eq_str("si je ne m'abuse.\n The end.");
    cr_assert(eq(i32, a, stu_strlen("si je ne m'abuse.\n The end.")));
}
