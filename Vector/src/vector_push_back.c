#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
#include "stu.h"

void stu_realloc(struct vector *ve)
{
    char *tamp;
    int newSize;

    newSize = ve->octUsed + (ve->Esize * 5);
    tamp = malloc(newSize);
    stu_memcpy(tamp, ve->ptr, ve->octUsed);
    free(ve->ptr);
    ve->ptr = malloc(newSize);
    ve->contenu = ve->ptr;
    stu_memcpy(ve->ptr, tamp, ve->octUsed);
    ve->octDisp = newSize;
    free(tamp);
}

void *vector_push_back(struct vector *ve, void *elem)
{
    char *to_cpy;
    int i;

    to_cpy = elem;
    i = 0;
    if (ve->octDisp <= ve->octUsed) {
        stu_realloc(ve);
    }
    if (ve->octDisp > ve->octUsed) {
        while (i < ve->Esize) {
            ve->contenu[ve->octUsed] = to_cpy[i];
            i += 1;
            ve->octUsed += 1;
        }
    }
    return ve->ptr;
}
