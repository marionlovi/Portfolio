#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

void *arrset(void *array,
	     const void *elem,
	     unsigned int elem_size,
	     unsigned int n)
{
    char *ptr_char;
    const char *ptr_elem;
    unsigned int idx_tab;
    unsigned int idx_elem;

    ptr_char = array;
    ptr_elem = elem;
    idx_tab = 0;
    idx_elem = 0;
    while (idx_tab < n) {
        idx_elem = 0;
        while (idx_elem < elem_size) {
            ptr_char[(idx_tab * elem_size) + idx_elem] = ptr_elem[idx_elem];
            idx_elem++;
        }
        idx_tab++;
    }
    return ptr_char;
}

