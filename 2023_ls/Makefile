SRCS =	src/strab.c\
	src/ls.c\
	src/ls_with_opt.c\
	src/stat_opt.c\
	src/print_perm.c\

OBJS =	$(SRCS:.c=.o)

SRCS_T = test/strab_test.c\
	test/count_files.test.c\
	test/ls_with_opt.test.c\
	test/search_opt.test.c\

OBJS_T =	$(SRCS_T:.c=.o)

LDFLAGS = -lcriterion

CFLAGS = -g -Wall -Wextra -Werror -I../libstu/include -Iinclude

LIBPATH = ../libstu/

all: ls

libstu.a:
	$(MAKE) -C $(LIBPATH) libstu.a
	cp $(LIBPATH)libstu.a ./
clean:
	$(MAKE) -C $(LIBPATH) clean
	@rm -vf $(OBJS) $(OBJS_T)

fclean: clean
	@rm -vf ls libstu.a ut.out
	$(MAKE) -C $(LIBPATH) fclean

ls:	libstu.a $(OBJS) src/main.o
	gcc -o ls $(OBJS) src/main.o libstu.a printf.a

ut.out: $(OBJS) $(OBJS_T) libstu.a
	$(CC) $(LDFLAGS) $(CFLAGS) -o ut.out $(OBJS) $(OBJS_T) libstu.a printf.a

test: ut.out
	./ut.out

re: fclean all

.PHONY: all clean fclean re test
