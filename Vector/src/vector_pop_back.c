#include "vecteur.h"
#include "stu.h"

void vector_pop_back(struct vector *ve)
{
    ve->octUsed -= ve->Esize;
}
