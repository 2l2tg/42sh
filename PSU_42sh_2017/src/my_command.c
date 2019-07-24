/*
** EPITECH PROJECT, 2018
** my_command
** File description:
** c file
*/

#include "mysh.h"

int my_command(p_cmd *cmd, int i, int u)
{
	cmd->tab = cmd->command[i][u];
	if (my_strcmp("cd", cmd->tab[0]) || my_strcmp("env", cmd->tab[0])) {
		if (my_strcmp("cd", cmd->tab[0]))
			my_cd(cmd->tab, cmd->env);
		else
			my_put_env(cmd->env);
	} else if (my_strcmp("setenv", cmd->tab[0])
	|| my_strcmp("unsetenv", cmd->tab[0])) {
		if (my_strcmp("setenv", cmd->tab[0]) && cmd->tab[1])
			my_setenv(cmd, 0);
		else if (cmd->tab[1])
			my_unsetenv(cmd, 0);
	} else
		return (1);
	if (cmd->command[i][u + 1] != NULL &&
		cmd->command[i][u + 1][0][1] == '&')
		condition_process(cmd, i, u + 2);
	return (0);
}
