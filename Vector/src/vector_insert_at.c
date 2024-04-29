#include "stu.h"
#include "vecteur.h"
#include <stdio.h>

void *vector_insert_at(struct vector *ve,
                       void *elem,
                       unsigned int pos)
{
    void *from;
    void *to;
    int mv_size;

    if (pos < vector_get_size(ve)) {
        if (ve->octDisp < ve->octUsed) {
            stu_realloc(ve);
        }
        from = vector_get_at(ve, pos);
        to = vector_get_at(ve, pos + 1);
        ve->octUsed += ve->Esize;
        mv_size = (vector_get_size(ve) - pos) * ve->Esize;
        stu_memmove(to, from, mv_size);
        stu_memcpy(from, elem, ve->Esize);
    }
    return ve->ptr;
}
