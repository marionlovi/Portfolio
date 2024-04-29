#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "ls.h"

Test(count_files, src)
{
    char *path;
    int res;

    path = "src";
    res = count_files(path);
    cr_assert(eq(i32, res, 12));
}

Test(count_files, include)
{
    char *path;
    int res;

    path = "include";
    res = count_files(path);
    cr_assert(eq(i32, res, 1));
}

Test(count_files, empty)
{
    char *path;
    int res;

    path = "./empty_dir";
    res = count_files(path);
    cr_assert(eq(i32, res, 0));
}

Test(count_files, unknow_dir)
{
    char *path;
    int res;

    path = "cool_dir";
    res = count_files(path);
    cr_assert(eq(i32, res, 0));
}

Test(count_all_files, src)
{
    char *path;
    int res;

    path = "src";
    res = count_all_files(path);
    cr_assert(eq(i32, res, 14));
}

Test(count_all_files, include)
{
    char *path;
    int res;

    path = "include";
    res = count_all_files(path);
    cr_assert(eq(i32, res, 3));
}

Test(count_all_files, empty)
{
    char *path;
    int res;

    path = "./empty_dir";
    res = count_all_files(path);
    cr_assert(eq(i32, res, 2));
}

Test(count_all_files, unknow_dir)
{
    char *path;
    int res;

    path = "cool_dir";
    res = count_all_files(path);
    cr_assert(eq(i32, res, 0));
}
