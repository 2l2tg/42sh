/*
** EPITECH PROJECT, 2018
** condition process
** File description:
** c file
*/

#include "mysh.h"

void condition_process_part2(p_cmd *cmd, int i, int u)
{
	if (cmd->command[i][u + 3][0][0] == '|') {
		pipe_process(cmd, i, u + 2);
	} else if (cmd->command[i][u + 3][0][0] == '>') {
		link_files(cmd, i, u + 2, 1);
		child_process(cmd);
	}
}

int condition_process(p_cmd *cmd, int i, int u)
{
	int ret = 0;

	cmd->tab = cmd->command[i][u];
	ret = child_process(cmd);
	if (cmd->command[i][u + 1] != NULL &&
		((cmd->command[i][u + 1][0][0] == '&' && ret == 0) ||
		(cmd->command[i][u + 1][0][1] == '|' && ret > 0))) {
		if (cmd->command[i][u + 3] == NULL) {
			cmd->tab = cmd->command[i][u + 2];
			child_process(cmd);
		} else if (cmd->command[i][u + 3][0][1] == '|' ||
			cmd->command[i][u + 3][0][1] == '&') {
			condition_process(cmd, i, u + 2);
		} else
			condition_process_part2(cmd, i, u);
	}
	return (0);
}
