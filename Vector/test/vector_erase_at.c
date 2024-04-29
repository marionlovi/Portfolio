#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include <stdlib.h>
#include "vecteur.h"

Test(vector_erase_at, int) {
    int i;
    int x;

    i = 0;
    x = 10;
    struct vector *ve;
    ve = vector_create(sizeof(int), 5);
    while (i < 5 ) {
        vector_push_back(ve, &x);
        x += 15;
        i += 1;
    }
    x = *(int *)vector_get_at(ve, 2);
    vector_erase_at(ve, 2);
    cr_expect(ne(i32, *(int *)vector_get_at(ve, 2), x));
    vector_delete(ve);
}

Test(vector_erase_at, intbig) {
    int i;
    int x;

    i = 0;
    x = 1;
    struct vector *ve;
    ve = vector_create(sizeof(int), 5);
    while (i < 50) {
        vector_push_back(ve, &x);
        x += 1;
        i += 1;
    }
    x = *(int *)vector_get_at(ve, 5);
    vector_erase_at(ve, 5);
    cr_expect(ne(i32, *(int *)vector_get_at(ve, 5), x));
    vector_delete(ve);
}

Test(vector_erase_at, alphabet) {
    int i;
    char x;

    i = 0;
    x = 'a';
    struct vector *ve;
    ve = vector_create(sizeof(char), 5);
    while (i < 10) {
        vector_push_back(ve, &x);
        x += 1;
        i += 1;
    }
    x = *(char *)vector_get_at(ve, 2);
    vector_erase_at(ve, 2);
    cr_expect(ne(i32, *(char *)vector_get_at(ve, 2), x));
    vector_delete(ve);
}
