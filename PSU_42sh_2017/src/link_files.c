/*
** EPITECH PROJECT, 2018
** link files
** File description:
** c file
*/

#include "mysh.h"

void link_files(p_cmd *cmd, int i, int y, int oldfd)
{
	int u = y;
	int fd;
	int flags;

	if (cmd->command[i][u + 1]) {
		if (cmd->command[i][u + 1][0][1] == '>')
			flags = O_RDWR + O_CREAT + O_APPEND;
		else
			flags = O_RDWR + O_CREAT + O_TRUNC;
		fd = open(cmd->command[i][u + 2][0], flags, 0666);
		if (cmd->command[i][u + 3] &&
			cmd->command[i][u + 3][0][0] == '>')
			link_files(cmd, i, y + 2, 1);
		else
			dup2(fd, oldfd);
	}
}

void redirection_process_part2(p_cmd *cmd, int i, int u)
{
	int fd;
	char *file = NULL;
	char **tab = NULL;
	int x = 0;

	fd = open(cmd->command[i][u + 2][0], O_RDONLY);
	file = get_file(fd);
	fd = open(".tmp", O_RDWR + O_CREAT + O_TRUNC, 0666);
	write(fd, file, my_strlen(file));
	tab = malloc(sizeof(char *) * (my_tablen(cmd->command[i][0]) + 1));
	while (cmd->command[i][u][x]) {
		tab[x] = cmd->command[i][u][x];
		x++;
	}
	cmd->command[i][0][x] = malloc(sizeof(char) * 5);
	cmd->command[i][0][x][0] = '.';
	cmd->command[i][0][x][1] = 't';
	cmd->command[i][0][x][2] = 'm';
	cmd->command[i][0][x][3] = 'p';
	cmd->command[i][0][x][4] = '\0';
	cmd->command[i][0][x + 1] = NULL;

}

void redirection_process(p_cmd *cmd, int i, int u)
{
	if (cmd->command[i][u + 1]) {
		if (cmd->command[i][u + 3] &&
			cmd->command[i][u + 3][0][0] == '<' &&
			cmd->command[i][u + 3][0][1] == '\0')
			redirection_process(cmd, i, u + 2);
		else
			redirection_process_part2(cmd, i, u);
	}
}
