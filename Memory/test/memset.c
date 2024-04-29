#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "memory.h"

Test(stu_memset, norm1) {
    unsigned int arr_size;
    int *array;
    int j;

    j = 0;
    arr_size = sizeof(int) * 12;
    array = malloc(arr_size);
    stu_memset(array, 0, arr_size);
    while (j != 12) {
        printf("%d\n", array[j]);
        cr_expect(eq(array[j], 0));
        j = j + 1;
    }
    free(array);
}
