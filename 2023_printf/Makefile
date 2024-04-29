SRCS =	src/printBase_opt.c \
	src/printf.c \
	src/writing_opt.c \

SRCS_T = test/printf_opt_c.c \
	test/printf_opt_s.c \
	test/printf_opt_d.c \

OBJS =	$(SRCS:.c=.o)
OBJS_T =	$(SRCS_T:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -I../libstu/include -Iinclude

LDFLAGS = -lcriterion

LIBPATH = ../libstu/

all: ut.out

ut.out: $(OBJS) $(OBJS_T) libstu.a
	$(CC) $(LDFLAGS) $(CFLAGS) -o ut.out $(OBJS) $(OBJS_T) printf.a

test: ut.out
	./ut.out

libstu.a:
	$(MAKE) -C $(LIBPATH) libstu.a
	cp $(LIBPATH)libstu.a

printf.a: $(OBJS)
	 ar rc printf.a $(OBJS)

clean:
	$(MAKE) -C $(LIBPATH) clean
	@rm -vf $(OBJS)

fclean: clean
	@rm -vf d2 libstu.a ut.out printf.a
	$(MAKE) -C $(LIBPATH) fclean

d5: libstu.a $(OBJS)
	gcc -o d5 $(OBJS) libstu.a

re: fclean all

.PHONY: all clean fclean re test
