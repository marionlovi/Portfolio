#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include <stdlib.h>
#include "vecteur.h"

Test(vector_pop_back, int) {
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
    x = ve->contenu[ve->octUsed];
    vector_pop_back(ve);
    cr_expect(ne(i32, ve->contenu[ve->octUsed], x));
    vector_delete(ve);
}

Test(vector_pop_back, intbig) {
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
    x = ve->contenu[ve->octUsed];
    vector_pop_back(ve);
    cr_expect(ne(i32, ve->contenu[ve->octUsed], x));
    vector_delete(ve);
}

Test(vector_pop_back, alphabet) {
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
    x = ve->contenu[ve->octUsed - ve->Esize];
    vector_pop_back(ve);
    cr_expect(ne(i32, ve->contenu[ve->octUsed - ve->Esize], x));
    vector_delete(ve);
}
