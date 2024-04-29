SRCS =	src/vector_create.c \
	src/vector_delete.c \
	src/vector_push_back.c \
	src/vector_pop_back.c \
	src/vector_pop_front.c \
	src/vector_get.c \
	src/vector_front_push.c \
	src/vector_insert_at.c \
	src/vector_erase_at.c \

SRCS_T =	test/vector_create.c \
	test/vector_delete.c \
	test/vector_push_back.c \
	test/vector_pop_back.c \
	test/vector_pop_front.c \
	test/vector_get.c \
	test/vector_front_push.c\
	test/vector_insert_at.c \
	test/vector_erase_at.c \

OBJS = $(SRCS:.c=.o)
OBJS_T = $(SRCS_T:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -I../libstu/include -Iinclude

LDFLAGS = -lcriterion

LIBPATH = ../libstu/

all: test

ut.out: $(OBJS) $(OBJS_T) libstu.a
	$(CC) $(LDFLAGS) $(CFLAGS) -o ut.out $(OBJS) $(OBJS_T) libstu.a

test: ut.out
	./ut.out

libstu.a:
	$(MAKE) -C $(LIBPATH) libstu.a
	cp $(LIBPATH)libstu.a ./
clean:
	$(MAKE) -C $(LIBPATH) clean
	@rm -vf $(OBJS) $(OBJS_T)

fclean: clean
	@rm -vf d2 libstu.a ut.out
	$(MAKE) -C $(LIBPATH) fclean

d2: libstu.a $(OBJS)
	gcc -o d2 $(OBJS) libstu.a

re: fclean all

.PHONY: all clean fclean re test
