/*
** EPITECH PROJECT, 2018
** mysh.h
** File description:
** h file
*/

#ifndef MYSH_H
#define MYSH_H

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef struct s_cmd {
	char **env;
	char *str;
	char **tab;
	char ****command;
	char ****command2;
	int j;
	int t;
}		p_cmd;

void my_putchar(char);
void my_put_nbr(int);
void my_put_str(char *);
int my_put_ret(char *);
void my_put_err(char *);
char *my_strcpy(char *);
char *my_copy_str(char *);
char *my_strcat(char *, char *);
char *my_strcat_sep(char *, char *);
int my_strlen(char *);
int my_tablen(char **);
int my_strlen_to(char *, int, char);
int my_command(p_cmd *, int, int);
int my_cd(char **, char **);
int my_strcmp(char *, char *);
int my_strcmp_to(char *, char *);
char **copy_env(char **, int);
void my_put_env(char **);
char **my_str_to_word_tab(char *, int);
int shell(p_cmd *);
void exec(char **, char **);
int my_setenv(p_cmd *, int);
int my_unsetenv(p_cmd *, int);
void free_tab(char **);
void get_commands(p_cmd *);
int nb_command(p_cmd *);
int get_first_command_pos(p_cmd *);
int get_command_start_pos(p_cmd *, int);
int get_command_end_pos(p_cmd *, int);
int get_nb_simple_command(p_cmd *, int, int);
int get_len_simple_command(p_cmd *, int);
int get_nb_words(p_cmd *, int, int);
int check_command(p_cmd *);
int check_exit(p_cmd *);
int command_check(p_cmd *, int);
int command_check2(p_cmd *, int);
int command_check3(p_cmd *, int);
void malloc_command2(p_cmd *, int, int);
int add_redic(p_cmd *, int, int, int);
int add_simple_command(p_cmd *, int, int, int);
int condition_process(p_cmd *, int, int);
int my_error(char *);
char *get_next_line(int);
char **my_unsetenv2(p_cmd *, char **, int);
int check_setenv(p_cmd *);
int pipe_process(p_cmd *, int, int);
int child_process(p_cmd *);
void link_files(p_cmd *, int, int, int);
void redirection_process(p_cmd *, int, int);
char *get_file(int);

#endif /* MYSH_H */
