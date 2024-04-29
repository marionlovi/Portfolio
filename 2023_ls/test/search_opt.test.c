#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "ls.h"

Test(search_opt, opt_a)
{
    struct options opts;
    char opt;
    int res;

    opt = 'a';
    res = search_opt(opt, &opts);
    cr_assert(eq(i32, opts.opt_a, 1));
    cr_assert(eq(i32, res, 1));
}

Test(search_opt, opt_c)
{
    struct options opts;
    char opt;
    int res;

    opt = 'c';
    res = search_opt(opt, &opts);
    cr_assert(eq(i32, opts.opt_c, 1));
    cr_assert(eq(i32, res, 1));
}

Test(search_opt, opt_l)
{
    struct options opts;
    char opt;
    int res;

    opt = 'l';
    res = search_opt(opt, &opts);
    cr_assert(eq(i32, opts.opt_l, 1));
    cr_assert(eq(i32, res, 1));
}

Test(search_opt, opt_h)
{
    struct options opts;
    char opt;
    int res;

    opt = 'h';
    res = search_opt(opt, &opts);
    cr_assert(eq(i32, opts.opt_h, 1));
    cr_assert(eq(i32, res, 1));
}

Test(search_opt, unknow_opt)
{
    struct options opts;
    char opt;
    int res;

    opt = 'b';
    res = search_opt(opt, &opts);
    cr_assert(ne(i32, opts.opt_a, 1));
    cr_assert(ne(i32, opts.opt_c, 1));
    cr_assert(ne(i32, opts.opt_l, 1));
    cr_assert(ne(i32, opts.opt_h, 1));
    cr_assert(eq(i32, res, 0));
}
