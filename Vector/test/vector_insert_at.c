#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdlib.h>
#include "stu.h"
#include "vecteur.h"

Test(vector_insert_at, int) {
    int i;
    int x;

    i = 0;
    x = 0;
    struct vector *ve;
    ve = vector_create(sizeof(int), 4);
    while (i <= 10) {
        vector_push_back(ve, &x);
        x += 1;
        i += 1;
    }
    i = 0;
    x = 45;
    vector_insert_at(ve, &x, 3);
    cr_expect(eq(i32, ve->contenu[2 * ve->Esize], x ));
    x = 5;
    vector_insert_at(ve, &x, 6);
    cr_expect(eq(i32, ve->contenu[5 * ve->Esize], x ));
    vector_delete(ve);
}

Test(vector_insert_at, char) {
    int i;
    char x;
    struct vector *ve;

    i = 0;
    x = 'a';
    ve = vector_create(sizeof(char), 4);
    while (i <= 10) {
        vector_push_back(ve, &x);
        x += 1;
        i += 1;
    }
    i = 0;
    x = 'g';
    vector_insert_at(ve, &x, 3);
    cr_expect(eq(ve->contenu[2 * ve->Esize], x ));
    x = 'z';
    vector_insert_at(ve, &x, 6);
    cr_expect(eq(ve->contenu[5 * ve->Esize], x ));
    vector_delete(ve);
}
