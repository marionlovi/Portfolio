CFLAGS = -Wall -Wextra -Werror -Iinclude

LDFLAGS = -lcriterion

CC = clang

SRCS =	src/arrset.c \
	src/memcpy.c \
	src/memset.c \
	src/memmove.c

SRCS_T =	test/arrset.c \
	test/memcpy.c \
	test/memset.c \
	test/memmove.c


OBJS = $(SRCS:.c=.o)
OBJS_T = $(SRCS_T:.c=.o)

all: libstu.a

libstu.a: $(OBJS)
	ar rc libstu.a $(OBJS)

ut.out: $(OBJS) $(OBJS_T)
	$(CC) $(LDFLAGS) -o ut.out $(OBJS) $(OBJS_T)

test: ut.out
	./ut.out

clean:
	@rm -vf $(OBJS) $(OBJS_T) libstu.a ut.out *~ *# src/*~ src/*# test/*# test/*~ include/*# include/*~

fclean: clean
	@rm -vf libstu.a ut.out

re: fclean all


.PHONY: all clean fclean re test
