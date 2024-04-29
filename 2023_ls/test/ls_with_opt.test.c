#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ls.h"

Test(store_files, empty_case)
{
    char *path;
    char **files;

    path = "empty_dir";
    files = store_files(path);
    cr_assert(files, "store_files should return NULL for empty dir");
    free(files);
}

Test(store_files, normal)
{
    char *path;
    char **files;

    path = "src";
    files = store_files(path);
    cr_assert(files, "store_files should return NULL for empty dir");
    free(files);
}

Test(store_all_files, empty_case)
{
    char *path;
    char **files;

    path = "empty_dir";
    files = store_all_files(path);
    cr_assert(files, "store_files should return NULL for empty dir");
    free(files);
}

Test(store_all_files, normal)
{
    char *path;
    char **files;

    path = "src";
    files = store_all_files(path);
    cr_assert(files, "store_files should return NULL for empty dir");
    free(files);
}
