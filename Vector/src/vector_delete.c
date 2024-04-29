#include <stdlib.h>
#include "vecteur.h"
#include "stu.h"

void vector_delete(struct vector *ve)
{
        free(ve->ptr);
        free(ve);
}
