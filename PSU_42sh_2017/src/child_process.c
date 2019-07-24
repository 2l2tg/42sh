/*
** EPITECH PROJECT, 2018
** child process
** File description:
** c file
*/

#include "mysh.h"

int child_process(p_cmd *cmd)
{
	pid_t pid;
	int ret = 0;

	pid = fork();
	if (pid == 0) {
		exec(cmd->tab, cmd->env);
	} else {
		wait(&ret);
		if (ret == 139 || ret == 11)
			my_put_str("Segmentation fault\n");
		else if (ret == 136)
			my_put_str("Floating exception\n");
		else if (ret == -1) {
			my_put_str(cmd->tab[0]);
			my_put_str(": Exec format error. Wrong Architecture.");
		}
		return (ret);
	}
	return (0);
}
