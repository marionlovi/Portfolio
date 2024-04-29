#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include "vecteur.h"

Test(vector_create, int) {
    struct vector *ve;
    ve = vector_create(sizeof(int), 5);
    cr_expect(ne(ve, NULL));
    cr_expect(ne(ve->ptr, NULL));
    cr_expect(eq(i32, ve->Esize, sizeof(int)));
    cr_expect(eq(i32, ve->octDisp, sizeof(int) * 5));
    vector_delete(ve);
}

Test(vector_create, char) {
    struct vector *ve;
    ve = vector_create(sizeof(char), 5);
    cr_expect(ne(ve, NULL));
    cr_expect(ne(ve->ptr, NULL));
    cr_expect(eq(i32, ve->Esize, sizeof(char)));
    cr_expect(eq(i32, ve->octDisp, sizeof(char) * 5));
    vector_delete(ve);
}

