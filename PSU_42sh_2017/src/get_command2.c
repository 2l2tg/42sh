/*
** EPITECH PROJECT, 2018
** get_command2.C
** File description:
** next function of get_command1.c
*/

#include "mysh.h"

int add_command(p_cmd *cmd, int i, int p)
{
	int m = 0;

	while (cmd->str[i] && cmd->str[i] != ';') {
		malloc_command2(cmd, p, m);
		if (cmd->str[i] == '>' || cmd->str[i] == '<'
		|| cmd->str[i] == '|' || cmd->str[i] == '&') {
			i = add_redic(cmd, i, p, m);
		} else
			i = add_simple_command(cmd, i, p, m);
		while (cmd->str[i] == ' ' || cmd->str[i] == '\t')
			i++;
		m++;
	}
	return (i);
}

void malloc_command(p_cmd *cmd, int p)
{
	int i = 0;

	cmd->command2 = cmd->command;
	cmd->command = malloc(sizeof(char ***) * (p + 2));
	while (cmd->command2 && cmd->command2[i]) {
		cmd->command[i] = cmd->command2[i];
		i++;
	}
	cmd->command[i] = 0;
	cmd->command[i + 1] = 0;
}

void get_commands(p_cmd *cmd)
{
	int i = 0;
	int p = 0;

	cmd->command = NULL;
	cmd->command2 = NULL;
	cmd->tab = NULL;
	while (cmd->str[i] == ' ' || cmd->str[i] == '\t' || cmd->str[i] == ';')
		i++;
	while (cmd->str[i]) {
		malloc_command(cmd, p);
		i = add_command(cmd, i, p);
		while (cmd->str[i] == ' ' || cmd->str[i] == '\t'
		|| cmd->str[i] == ';')
			i++;
		p++;
	}
}
