#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "stu.h"
#include "vecteur.h"

Test(vector_delete, int) {
    struct vector *ve;
    ve = vector_create(sizeof(int), 5);
    vector_delete(ve);
}

Test(vector_delete, char) {
    struct vector *ve;
    ve = vector_create(sizeof(int), 5);
    vector_delete(ve);
}
