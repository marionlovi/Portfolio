#include "memory.h"

void *stu_memset(void *ptr, char byte, unsigned int n)
{
    char *pointeur2;
    unsigned int j;

    j = 0;
    pointeur2 = ptr;
    while (j != n) {
        pointeur2[j] = byte;
        j = j + 1;
    }
    return ptr;
}
