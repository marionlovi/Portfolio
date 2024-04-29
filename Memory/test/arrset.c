#include <criterion/redirect.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdlib.h>
#include "memory.h"

Test(arrset, norm1) {
    int *array;
    const unsigned int elem_size = sizeof(int);
    const int default_value = 1970;

    array = malloc(elem_size * 89);
    arrset(array, &default_value, elem_size, 89);
// chaque case du tableau vaut maintenant 1970
    unsigned int i;

    i = 0;
    while (i < 89) {
        cr_assert(eq(i32, array[i], 1970), "array[%u] isn't equal to 1970", i);
	// dans un main
	//printf("array[%u]: %d\n", i, array[i]);
	i += 1;
    }
    free(array);
}
