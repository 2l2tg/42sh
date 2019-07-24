##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/main.c			\
		src/shell.c			\
		src/pipe_process.c		\
		src/condition_process.c		\
		src/link_files.c		\
		src/child_process.c		\
		src/exec.c			\
		src/command_check.c		\
		src/get_command1.c		\
		src/get_command2.c		\
		src/my_cd.c			\
		src/my_command.c		\
		src/my_env.c			\
		src/my_copy_str.c		\
		src/my_putchar.c		\
		src/my_put_str.c		\
		src/my_put_nbr.c		\
		src/my_strcpy.c			\
		src/my_strcat.c			\
		src/my_strcmp.c			\
		src/my_strlen.c			\
		src/my_error.c			\
		src/my_str_to_word_tab.c	\
		src/get_next_line.c		\
		src/get_file.c			\
		src/my_env2.c

NAME	=	42sh

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -fno-builtin -g -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
