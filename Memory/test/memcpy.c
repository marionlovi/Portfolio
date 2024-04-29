#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "memory.h"

Test(stu_memcpy, norm1) {
    unsigned int arr_size;
    int *src;
    int *dest;
    int j;

    j = 0;
    arr_size = sizeof(int) * 12;
    src = malloc(arr_size);
    dest = malloc(arr_size);
    stu_memset(src, 0, arr_size);
    stu_memcpy(dest, src, arr_size);
    while (j != 12) {
        cr_log_info("%d\n", dest[j]);
        cr_expect(eq(dest[j], src[j]));
        j = j + 1;
    }
    free(dest);
    free(src);
}
