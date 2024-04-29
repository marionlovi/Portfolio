#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"

void strtab_sort(char **strtab);

Test(starb, normal_1)
{
    char *strtab[] = {"abc", "def", "ghi", NULL};

    strtab_sort(strtab);
    cr_assert(eq(str, strtab[0], "abc"));
    cr_assert(eq(str, strtab[1], "def"));
    cr_assert(eq(str, strtab[2], "ghi"));
}

Test(starb, repetition)
{
    char *strtab[] = {"abc", "def", "abc", NULL};

    strtab_sort(strtab);
    cr_assert(eq(str, strtab[0], "abc"));
    cr_assert(eq(str, strtab[1], "abc"));
    cr_assert(eq(str, strtab[2], "def"));
}

Test(starb, len)
{
    char *strtab[] = {"aaa", "ab", "c", NULL};

    strtab_sort(strtab);
    cr_assert(eq(str, strtab[0], "aaa"));
    cr_assert(eq(str, strtab[1], "ab"));
    cr_assert(eq(str, strtab[2], "c"));
}

Test(starb, empty)
{
  char *strtab[] = {NULL};

  strtab_sort(strtab);
  cr_assert(strtab[0] == NULL, "Expected NULL, but got %p", strtab[0]);
}
