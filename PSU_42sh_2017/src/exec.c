/*
** EPITECH PROJECT, 2018
** exec
** File description:
** c file
*/

#include "mysh.h"

int check_file(char **tab, char **env)
{
	if (opendir(tab[0]) != NULL) {
		my_put_str(tab[0]);
		my_put_str(": Permission denied.\n");
		return (84);
	} else if (access(tab[0], X_OK) == 0) {
		execve(tab[0], tab, env);
		my_put_str(tab[0]);
		my_put_str(": Permission denied.\n");
		return (84);
	}
	return (0);
}

void exec_path(char **tab, char **env, int i)
{
	char **tab_path = NULL;
	char *path = NULL;
	int u = 0;

	if (check_file(tab, env) == 84)
		return;
	tab_path = my_str_to_word_tab(env[i], 5);
	while (tab_path[u]) {
		path = my_strcat_sep(tab_path[u], tab[0]);
		if (access(path, X_OK) == 0)
			execve(path, tab, env);
		free(path);
		path = NULL;
		u++;
	}
	my_put_str(tab[0]);
	my_put_str(": Command not found.\n");
}

void exec(char **tab, char **env)
{
	int i = 0;

	while (env[i] && my_strcmp_to("PATH=", env[i]) == 0)
		i++;
	if (env[i] && my_strcmp_to("PATH=", env[i]))
		exec_path(tab, env, i);
	else if (check_file(tab, env) == 0) {
		my_put_str(tab[0]);
		my_put_str(": Command not found.\n");
		return;
	}
	return;
}
