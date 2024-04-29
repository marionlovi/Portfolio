#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "memory.h"

Test(memmove, rightward) {
    int *arr;
    int i;
    int cmp;

    arr = malloc(sizeof(int) * 4);
    arr[0] = 4;
    arr[1] = 5;
    arr[2] = 6;
    stu_memmove(&arr[1], arr, sizeof(int) * 3);
    arr[0] = 3;
    i = 0;
    cmp = 3;
    while (i < 4) {
        cr_expect(eq(i32, arr[i], cmp));
        i += 1;
        cmp += 1;
    }
}

Test(memmove, leftward) {
    int *arr;
    int i;
    int cmp;

    arr = malloc(sizeof(int) * 4);
    arr[0] = 3;
    arr[1] = 4;
    arr[2] = 5;
    arr[3] = 6;
    stu_memmove(arr, &arr[1], sizeof(int) * 3);
    i = 0;
    cmp = 4;
    while (i < 3) {
        cr_expect(eq(i32, arr[i], cmp));
        i += 1;
        cmp += 1;
    }
}
