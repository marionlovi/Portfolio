#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include <stdlib.h>
#include "vecteur.h"

Test(vector_push_back, int) {
    int i;
    int x;

    i = 0;
    x = 10;
    struct vector *ve;
    ve = vector_create(sizeof(int), 5);
    while (i <= 5) {
        vector_push_back(ve, &x);
        cr_expect(eq(i32, ve->contenu[i * ve->Esize], x));
        cr_expect(eq(i32, ve->octUsed, i * ve->Esize + ve->Esize));
        x += 15;
        i += 1;
    }
    vector_delete(ve);
}

Test(vector_push_back, intbig) {
    int i;
    int x;

    i = 0;
    x = 1;
    struct vector *ve;
    ve = vector_create(sizeof(int), 5);
    while (i <= 8) {
        vector_push_back(ve, &x);
        cr_expect(eq(i32, ve->contenu[i * ve->Esize], x));
        cr_expect(eq(i32, ve->octUsed, i * ve->Esize + ve->Esize));
        x += 1;
        i += 1;
    }
    vector_delete(ve);
}

Test(vector_push_back, alphabet) {
    int i;
    char x;

    i = 0;
    x = 'a';
    struct vector *ve;
    ve = vector_create(sizeof(char), 5);
    while (i < 8) {
        vector_push_back(ve, &x);
        cr_expect(eq(ve->contenu[i * ve->Esize], x));
        cr_expect(eq(i32, ve->octUsed, i * ve->Esize + ve->Esize));
        x += 1;
        i += 1;
    }
    vector_delete(ve);
}
