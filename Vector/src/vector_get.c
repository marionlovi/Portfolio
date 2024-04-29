#include "vecteur.h"
#include "stu.h"

void *vector_get_at(const struct vector *ve, unsigned int pos)
{
    void *get_it;

    get_it = &ve->contenu[(pos * ve->Esize) - ve->Esize];
    return get_it;
}

void *vector_get_front(const struct vector *ve)
{
    void *get_it;

    get_it = &ve->contenu[0];
    return get_it;
}

void *vector_get_back(const struct vector *ve)
{
    void *get_it;

    get_it = &ve->contenu[ve->octUsed - ve->Esize];
    return get_it;
}

unsigned int vector_get_size(const struct vector *ve)
{
    int size;

    size = ve->octUsed / ve->Esize;
    return size;
}

unsigned int vector_get_capacity(const struct vector *ve)
{
    int capacity;

    capacity = ve->octDisp / ve->Esize;
    return capacity;
}
