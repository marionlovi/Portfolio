#include <stdlib.h>
#include <stdio.h>
#include "vecteur.h"
#include "stu.h"

struct vector *vector_create(unsigned int elem_size,
			     unsigned int initial_capacity)
{
    struct vector *tab;

    tab = malloc(sizeof(struct vector));
    tab->ptr = malloc(elem_size * initial_capacity);
    tab->contenu = tab->ptr;
    tab->Esize = elem_size;
    tab->octDisp = elem_size * initial_capacity;
    tab->octUsed = 0;
    return tab;
}
