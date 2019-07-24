/*
** EPITECH PROJECT, 2018
** shell
** File description:
** c file
*/

#include "mysh.h"

void check_ret(p_cmd *cmd)
{
	int ret = -1;

	wait(&ret);
	if (ret == 139 || ret == 11) {
		my_put_str("Segmentation ");
		my_put_str("fault\n");
	} else if (ret == 136) {
		my_put_str("Floating ");
		my_put_str("exception\n");
	} else if (ret == -1) {
		my_put_str(cmd->tab[0]);
		my_put_str(": Exec format ");
		my_put_str("error. Wrong ");
		my_put_str("Architecture.\n");
	}
}

int send_command(p_cmd *cmd, int i)
{
	if (command_check(cmd, i) == 1 || command_check(cmd, i) == 5) {
		if (command_check(cmd, i) == 1)
			link_files(cmd, i, 0, 1);
		else
			redirection_process(cmd, i, 0);
		cmd->tab = cmd->command[i][0];
		child_process(cmd);
	} else if (command_check(cmd, i) == 2)
		pipe_process(cmd, i, 0);
	else if (command_check(cmd, i) == 3 ||
		command_check(cmd, i) == 4)
		condition_process(cmd, i, 0);
	return (1);
}

int check_send_command(p_cmd *cmd, int i)
{
	pid_t pid;
	if (my_command(cmd, i, 0) == 1) {
		pid = fork();
		if (pid == 0)
			return (send_command(cmd, i));
		else
			check_ret(cmd);
	}
	return (0);
}

int shell_loop(p_cmd *cmd)
{
	int i = 0;

	while (cmd->command != NULL && cmd->command[i]
		&& check_command(cmd) == 1) {
			if (check_send_command(cmd, i))
				return (1);
		i++;
	}
	return (0);
}

int shell(p_cmd *cmd)
{
	cmd->str = NULL;
	while ((cmd->str = get_next_line(0)) != NULL) {
		get_commands(cmd);
		if (cmd->command != NULL && check_exit(cmd) == 1)
			return (my_put_ret("exit\n"));
		if (shell_loop(cmd))
			return (0);
		if (isatty(0))
			my_put_str("$> ");
	}
	return (0);
}
