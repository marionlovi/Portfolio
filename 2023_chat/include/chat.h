/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-15 - 10:17 +0200
 * 1st author:  tony.yam - tony.yam
 * description: chat.h
 */

#ifndef CHAT_H_
#define CHAT_H_

struct information {
    struct pollfd *fds;
    char **nickname;
    int nb_client;
    int client_action;
    char *msg;
    int limite;
};

struct command_table_row {
    char *slash_command;
    int (*fptr)(struct information *info);
};

int stu_memset(char *str, int nb);
void disconnect_client(struct pollfd *fds, int qui,
                       int *nb_client, char **nicknames);
int stu_strcmp(const char *s1, const char *s2);
int stu_strsemicmp(const char *s1, const char *s2);
struct pollfd *add_client(struct pollfd *fds, int *limite);
char **add_nicknames(int limite,char **nicknames);
char **create_nicknames_list(int nb, char **nicknames);
int just_be_unique(int nb_client, char **nicknames, char *nick_potentiel);
void disconnect_client(struct pollfd *fds, int qui,
                       int *nb_client, char **nicknames);
void max_client(int sock);
char *stu_strdup(char *str);
void *stu_memcpy(void *dest, const void *src, unsigned int n);
void connect_client(struct pollfd *fds, int *nb_client,
                    int sock, char **nicknames);
int end_server(struct information *info);
int set_nicknames(int nb_client, int fd_client, char **nicknames);
int list(struct information *info);
int help(struct information *info);
void destroy_nicks(char **nicknames, int size);
int stu_atoi(const char *str);
char *has_opt_value(int ac, char **av, char str);
int has_opt(int ac, char **av, char str);
char *strdupcat(char *str1, char *str2);
int command(struct information *info);
int nick(struct information *info);
int create_session(int argc, char **argv, char *port);
int wisp(struct information *info);
char *forbidden_char(char *nick);
int kick(struct information *info);
int shut_down(struct information *info);
int handle_clients(struct information *info, char *str,
                   int *nb_client, int *work);

#endif
