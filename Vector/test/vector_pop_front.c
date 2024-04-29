#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include <stdlib.h>
#include "vecteur.h"

Test(vector_pop_front, int) {
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
    x = *(int *)vector_get_front(ve);
    vector_pop_front(ve);
    cr_expect(ne(i32, *(int *)vector_get_front(ve), x));
    vector_delete(ve);
}

Test(vector_pop_front, intbig) {
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
    x = *(int *)vector_get_front(ve);
    vector_pop_front(ve);
    cr_expect(ne(i32, *(int *)vector_get_front(ve), x));
    vector_delete(ve);
}

Test(vector_pop_front, alphabet) {
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
    x = *(char *)vector_get_front(ve);
    vector_pop_front(ve);
    cr_expect(ne(i32, *(char *)vector_get_front(ve), x));
    vector_delete(ve);
}
