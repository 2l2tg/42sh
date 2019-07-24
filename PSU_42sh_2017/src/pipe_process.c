/*
** EPITECH PROJECT, 2018
** pipe process
** File description:
** c file
*/

#include "mysh.h"

void pipe_process_part2(p_cmd *cmd, int i, int u)
{
	if (cmd->command[i][u + 3] != NULL) {
		if (cmd->command[i][u + 3][0][1] == '|' ||
			cmd->command[i][u + 3][0][1] == '&') {
			condition_process(cmd, i, u + 2);
		} else if (cmd->command[i][u + 3][0][0] == '>')
			link_files(cmd, i, u + 2, 1);
		link_files(cmd, i, u + 2, 1);
	}
	cmd->tab = cmd->command[i][u + 2];
	child_process(cmd);
}

int pipe_process(p_cmd *cmd, int i, int y)
{
	pid_t pid;
	int pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0) {
		dup2(pipefd[1], 1);
		cmd->tab = cmd->command[i][y];
		child_process(cmd);
	} else {
		dup2(pipefd[0], 0);
		if (cmd->command[i][y + 3] != NULL &&
			cmd->command[i][y + 3][0][0] == '|')
			pipe_process(cmd, i, y + 2);
		else
			pipe_process_part2(cmd, i, y);
	}
	close(pipefd[1]);
	close(pipefd[0]);
	return (0);
}
