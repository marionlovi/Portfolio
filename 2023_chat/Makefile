CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -Iinclude -I../2023_printf/include

NAME = chat_server

SRCS =  src/has_opt.c \
	src/has_opt_value.c \
	src/multi_echo.c \
	src/jbu.c \
	src/add_client.c \
	src/create_session.c \
	src/set_nicknames.c \
	src/forbidden_char.c \
	src/connect_client.c \
	src/max_client.c \
	src/strdupcat.c \
	src/stu_atoi.c \
	src/list.c \
	src/add_nicknames.c \
	src/create_nicknames_list.c \
	src/handle_clients.c \
	src/disconnect_client.c \
	src/help.c \
	src/memset.c \
	src/memcpy.c \
	src/strcmp.c \
	src/strsemicmp.c \
	src/destroy_nicks.c \
	src/end_serveur.c \
	src/strdup.c \
	src/command.c \
	src/nick.c \
	src/wisp.c \
	src/kick.c \
	src/shutdown.c \

TEST =

OBJS = $(SRCS:.c=.o)
TOBJS = $(TEST:.c=.o)
ALLBJS = $(OBJS) $(TOBJS)
NOBJS = $(OBJS) src/[NOM DU MAIN].c

all: $(NAME)

$(NAME): $(OBJS) printf.a
	$(CC) $(OBJS) printf.a -o $(NAME)

printf.a:
	$(MAKE) -C ../2023_printf/ all
	cp ../2023_printf/printf.a printf.a

ut.out: $(ALLBJS)
	$(CC) -lcriterion $(ALLBJS) -o ut.out

fclean: clean
	@rm -vf $(NAME)
	@rm -vf ut.out
	@rm -vf printf.a

clean:
	@rm -vf $(ALLBJS)

re: fclean all

.PHONY: all fclean clean
