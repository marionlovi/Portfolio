#include "memory.h"

void *stu_memmove(void *dest,
                   const void *src,
                   unsigned int n)
{
    char *tamp_dest;
    const char *tamp_src;
    unsigned int j;

    tamp_dest = dest;
    tamp_src = src;
    if (dest > src) {
        j = n;
        while (j > 0) {
            tamp_dest[j - 1] = tamp_src[j - 1];
            j = j - 1;
        }
    } else {
        j = 0;
        while (j < n) {
            tamp_dest[j] = tamp_src[j];
            j++;
        }
    }
    return dest;
}
