#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
#include "stu.h"

void *vector_push_front(struct vector *ve, void *elem)
{
    int i;
    char *newElmt;

    i = 0;
    newElmt = elem;
    if (ve->octDisp <= ve->octUsed) {
        stu_realloc(ve);
    }
    ve->octUsed += ve->Esize;
    stu_memmove(&ve->contenu[ve->Esize], ve->contenu,
                 (ve->octUsed));
    while (i < ve->Esize) {
        ve->contenu[i] = newElmt[i];
        i += 1;
    }
    return ve->ptr;
}
