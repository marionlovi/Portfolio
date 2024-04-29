#ifndef VECTOR_H_
#define VECTOR_H_

struct vector {
    void *ptr;
    char *contenu;
    int Esize;
    int octDisp;
    int octUsed;
};

void vector_pop_front(struct vector *ve);
void vector_erase_at(struct vector *ve, unsigned int pos);
void *stu_memcopy(void *dest, const void *src, unsigned int n);
void *vector_insert_at(struct vector *ve,
                       void *elem,
                       unsigned int pos);
void *vector_push_front(struct vector *ve, void *elem);
void stu_realloc(struct vector *ve);
void *vector_get_at(const struct vector *ve, unsigned int pos);
void *vector_get_front(const struct vector *ve);
void *vector_get_back(const struct vector *ve);
unsigned int vector_get_size(const struct vector *ve);
unsigned int vector_get_capacity(const struct vector *ve);
struct vector *vector_create(unsigned int elem_size,
			     unsigned int initial_capacity);
void vector_delete(struct vector *ve);
void *vector_push_back(struct vector *ve, void *elem);
void vector_pop_back (struct vector *ve);

#endif
