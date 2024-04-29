#include "vecteur.h"
#include "stu.h"

void vector_pop_front(struct vector *ve)
{
    if (vector_get_size(ve) > 0) {
        ve->octUsed -= ve->Esize;
        stu_memmove(ve->contenu, ve->contenu + ve->Esize, ve->octUsed);
    }
}
