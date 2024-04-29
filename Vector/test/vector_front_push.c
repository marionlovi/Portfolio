#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdlib.h>
#include "stu.h"
#include "vecteur.h"

Test(vector_push_front, char) {
    int i;
    char x;

    i = 0;
    x = 'd';
    struct vector *ve;
    ve = vector_create(sizeof(char), 6);
    while (i < 20) {
        vector_push_back(ve, &x);
        x += 1;
        i += 1;
    }
    i = 0;
    x = 'c';
    vector_push_front(ve, &x);
    x = 'b';
    vector_push_front(ve, &x);
    x = 'a';
    vector_push_front(ve, &x);
    cr_expect(eq(ve->contenu[0], 'a'));
    while (i < ve->octUsed / ve->Esize) {
        cr_expect(eq(ve->contenu[i * ve->Esize], x ));
        i += 1;
        x += 1;
    }
    vector_delete(ve);
}

Test(vector_push_front, int) {
    int i;
    int x;

    i = 0;
    x = 2;
    struct vector *ve;
    ve = vector_create(sizeof(int), 4);
    while (i <= 10) {
        vector_push_back(ve, &x);
        x += 1;
        i += 1;
    }
    i = 0;
    x = 1;
    vector_push_front(ve, &x);
    while (i < ve->octUsed / ve->Esize) {
        cr_expect(eq(i32, ve->contenu[i * ve->Esize], x ));
        i += 1;
        x += 1;
    }
    vector_delete(ve);
}

