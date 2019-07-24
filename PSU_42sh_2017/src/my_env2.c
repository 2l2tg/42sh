/*
** EPITECH PROJECT, 2018
** my_env
** File description:
** c file
*/

#include "mysh.h"

char **my_unsetenv2(p_cmd *cmd, char **new_env, int i)
{
	new_env[i - 1] = 0;
	while (cmd->env[i]) {
		new_env[i - 1] = cmd->env[i];
		new_env[i] = 0;
		i += 1;
	}
	free(cmd->env);
	cmd->env = new_env;
	return (new_env);
}

int check_setenv(p_cmd *cmd)
{
	int i = 0;

	if (cmd->tab[1][i] < 'A' || cmd->tab[1][i] > 'z') {
		my_put_str("setenv: Variable name must begin with a letter.\n");
		return (84);
	}
	while ((cmd->tab[1][i] >= 'A' && cmd->tab[1][i] <= 'z') ||
		(cmd->tab[1][i] >= '0' && cmd->tab[1][i] <= '9'))
		i++;
	if (cmd->tab[1][i] != '\0') {
		my_put_str("setenv: Variable name must contain alphanumeric ");
		my_put_str("characters.\n");
		return (84);
	}
	return (0);
}
