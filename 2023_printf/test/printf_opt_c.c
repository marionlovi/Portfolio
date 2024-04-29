#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu_printf.h"

Test(stu_dprintf, char)
{
    int a;

    cr_redirect_stdout();
    a = stu_dprintf(1, "to%co", 't');
    cr_assert_stdout_eq_str("toto");
    cr_assert(eq(i32, a, 4));
}

Test(stu_dprintf, vide)
{
    int a;
    cr_redirect_stdout();
    a = stu_dprintf(1, "");
    cr_assert_stdout_eq_str("");
    cr_assert(eq(i32, a, 0));
}

Test(stu_dprintf, char_loin)
{
    int a;
    cr_redirect_stdout();
    a = stu_dprintf(1, "% azerc", 't');
    cr_assert_stdout_eq_str("t");
    cr_assert(eq(i32, a, 1));
}

Test(stu_dprintf, multi_char)
{
    int a;
    cr_redirect_stdout();
    a = stu_dprintf(1, "% azerc%c%jjzkac%iekc %c", 't','o','t','o','0');
    cr_assert_stdout_eq_str("toto 0");
    cr_assert(eq(i32, a, 6));
}
