#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include <stdlib.h>
#include "vecteur.h"

Test(vector_get_at, int) {
    int i;
    int x;
    void *test;
    int *readable;

    i = 0;
    x = 10;
    struct vector *ve;
    ve = vector_create(sizeof(int), 5);
    while (i < 8 ) {
        vector_push_back(ve, &x);
        x += 15;
        i += 1;
    }
    test = vector_get_at(ve, 3);
    readable = test;
    cr_expect(eq(i32, *readable, 40));
    test = vector_get_front(ve);
    readable = test;
    cr_expect(eq(i32, *readable, 10));
    test = vector_get_back(ve);
    readable = test;
    cr_expect(eq(i32, *readable, 115));
    cr_expect(eq(i32, vector_get_size(ve), 8));
    cr_expect(eq(i32, vector_get_capacity(ve), 10));
    vector_delete(ve);
}
