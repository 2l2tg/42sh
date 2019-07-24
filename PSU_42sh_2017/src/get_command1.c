/*
** EPITECH PROJECT, 2018
** get command
** File description:
** c file
*/

#include "mysh.h"

int count_word(p_cmd *cmd, int i)
{
	int u = 0;

	while (cmd->str[i] && cmd->str[i] != ';' && cmd->str[i] != '<'
	&& cmd->str[i] != '>' && cmd->str[i] != '|' && cmd->str[i] != '&') {
		while (cmd->str[i] != ' ' && cmd->str[i] != '\t' && cmd->str[i]
		&& cmd->str[i] != ';' && cmd->str[i] != '<'
		&& cmd->str[i] != '>' && cmd->str[i] != '|'
		&& cmd->str[i] != '&') {
			i++;
		}
		while (cmd->str[i] == ' ' || cmd->str[i] == '\t')
			i++;
		u++;
	}
	return (u);
}

int get_word(p_cmd *cmd, int i, int p, int m)
{
	while (cmd->str[i] == ' ' || cmd->str[i] == '\t')
		i++;
	while (cmd->str[i] && cmd->str[i] != ';' && cmd->str[i] != '<'
	&& cmd->str[i] != '>' && cmd->str[i] != '|' && cmd->str[i] != '&'
	&& cmd->str[i] != ' ' && cmd->str[i] != '\t') {
		cmd->j++;
		i++;
	}
	cmd->command[p][m][cmd->t] = malloc(sizeof(char) * (cmd->j + 1));
	i -= cmd->j;
	cmd->j = 0;
	while (cmd->str[i] && cmd->str[i] != ';' && cmd->str[i] != '<'
	&& cmd->str[i] != '>' && cmd->str[i] != '|' && cmd->str[i] != '&'
	&& cmd->str[i] != ' ' && cmd->str[i] != '\t') {
		cmd->command[p][m][cmd->t][cmd->j] = cmd->str[i];
		cmd->j++;
		i++;
	}
	cmd->command[p][m][cmd->t][cmd->j] = 0;
	return (i);
}

int add_simple_command(p_cmd *cmd, int i, int p, int m)
{
	int len = count_word(cmd, i);
	int t = 0;

	cmd->command[p][m] = malloc(sizeof(char *) * (len + 1));
	while (t < len) {
		cmd->t = t;
		cmd->j = 0;
		i = get_word(cmd, i, p, m);
		t++;
	}
	cmd->command[p][m][t] = 0;
	return (i);
}

int add_redic(p_cmd *cmd, int i, int p, int m)
{
	int u = 0;

	cmd->command[p][m] = malloc(sizeof(char *) * 2);
	u++;
	while (cmd->str[i + u] == cmd->str[i + u - 1])
		u++;
	cmd->command[p][m][0] = malloc(sizeof(char) * (u + 1));
	u = 0;
	cmd->command[p][m][0][u] = cmd->str[i + u];
	u++;
	while (cmd->str[i + u] == cmd->str[i + u - 1]) {
		cmd->command[p][m][0][u] = cmd->str[i + u];
		u++;
	}
	cmd->command[p][m][0][u] = 0;
	cmd->command[p][m][1] = 0;
	i += u;
	wait(0);
	return (i);
}

void malloc_command2(p_cmd *cmd, int p, int m)
{
	int i = 0;
	char ***temp = cmd->command[p];

	cmd->command[p] = malloc(sizeof(char **) * (m + 2));
	while (temp && temp[i]) {
		cmd->command[p][i] = temp[i];
		i++;
	}
	cmd->command[p][i] = 0;
	cmd->command[p][i + 1] = 0;
}
