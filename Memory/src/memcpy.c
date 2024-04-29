#include "memory.h"

void *stu_memcpy(void *dest, const void *src, unsigned int n)
{
    const char *tamp_src;
    char *tamp_dest;
    unsigned int j;

    tamp_src = src;
    tamp_dest = dest;
    j = 0;
    while (j != n) {
        tamp_dest[j] = tamp_src[j];
        j = j + 1;
    }
    return dest;
}
