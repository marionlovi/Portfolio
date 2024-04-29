#ifndef MEMORY_H_
#define MEMORY_H_

void *stu_memmove(void *dest,
		  const void *src,
		  unsigned int n);
void *arrset(void *array,
	     const void *elem,
	     unsigned int elem_size,
	     unsigned int n);
void *stu_memset(void *ptr, char byte, unsigned int n);
void *stu_memcpy(void *dest, const void *src, unsigned int n);

#endif
