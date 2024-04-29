#include "vecteur.h"
#include "stu.h"

void vector_erase_at(struct vector *ve, unsigned int pos)
{
    void *from;
    void *to;
    int mv_size;

    if (pos < vector_get_size(ve)) {
        from = vector_get_at(ve, pos + 1);
        to = vector_get_at(ve, pos);
        mv_size = (vector_get_size(ve) - pos - 1) * ve->Esize;
        ve->octUsed -= ve->Esize;
        stu_memmove(to, from, mv_size);
    }
}
