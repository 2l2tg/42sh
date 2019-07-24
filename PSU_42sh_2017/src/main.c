/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** c file
*/

#include "mysh.h"

int main(int argc, char **argv, char **env)
{
	p_cmd cmd;

	(void)argc;
	(void)argv;
	cmd.env = copy_env(env, 0);
	signal(SIGINT, SIG_IGN);
	if (isatty(0))
		my_put_str("$> ");
	shell(&cmd);
	free_tab(cmd.env);
	if (cmd.str == NULL)
		my_put_str("exit\n");
	return (0);
}
