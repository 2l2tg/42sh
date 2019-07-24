/*
** EPITECH PROJECT, 2018
** command check
** File description:
** c file
*/

#include "mysh.h"

int command_check3(p_cmd *cmd, int i)
{
	int u = 0;

	while (cmd->command[i][u]) {
		u++;
		if (cmd->command[i][u] == NULL)
			return (0);
		if (my_strlen(cmd->command[i][u][0]) > 2)
			return (my_error(cmd->command[i][u][0]));
		u++;
	}
	return (0);
}

int command_check2(p_cmd *cmd, int i)
{
	int u = 0;
	char c;

	if (cmd->command[i][u]) {
		c = cmd->command[i][u][0][0];
		if (c == '<' || c == '>' || c == '|' || c == '&')
			return (my_error(cmd->command[i][u][0]));
	}
	return (0);
}

int command_check(p_cmd *cmd, int i)
{
	int u = 1;

	if (cmd->command[i][u] == NULL)
		return (1);
	if (cmd->command[i][u][0][0] == '>') {
		return (1);
	} else if (cmd->command[i][u][0][0] == '|') {
		if (cmd->command[i][u][0][1] == '\0')
			return (2);
		else
			return (4);
	} else if (cmd->command[i][u][0][0] == '<') {
		if (cmd->command[i][u][0][1] == '\0')
			return (5);
		else
			return (0);
	} else if (cmd->command[i][u][0][0] == '&')
		return (3);
	return (0);
}

int check_exit(p_cmd *cmd)
{
	int i = 0;
	int u = 0;

	while (cmd->command[i]) {
		u = 0;
		while (cmd->command[i][u]) {
			if (my_strcmp("exit", cmd->command[i][u][0]))
				return (1);
			u++;
		}
		i++;
	}
	return (0);
}

int check_command(p_cmd *cmd)
{
	int i = 0;

	while (cmd->command[i]) {
		if (command_check2(cmd, i) == 1 || command_check3(cmd, i) == 1)
			return (0);
		i++;
	}
	return (1);
}
