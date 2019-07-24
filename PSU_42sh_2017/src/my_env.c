/*
** EPITECH PROJECT, 2018
** my_env
** File description:
** c file
*/

#include "mysh.h"

int my_unsetenv(p_cmd *cmd, int i)
{
	char *path = my_strcat(cmd->tab[1], "=");
	char **new_env = NULL;

	while (cmd->env[i] && my_strcmp_to(path, cmd->env[i]) == 0)
		i++;
	if (cmd->env[i] == 0) {
		free(path);
		return (0);
	}
	new_env = malloc(sizeof(char *) * (my_tablen(cmd->env)));
	i = 0;
	while (cmd->env[i] && my_strcmp_to(path, cmd->env[i]) == 0) {
		new_env[i] = cmd->env[i];
		i++;
	}
	free(path);
	free(cmd->env[i]);
	i++;
	new_env = my_unsetenv2(cmd, new_env, i);
	return (0);
}

void add_path_in_env(p_cmd *cmd, char *path)
{
	char **new_env = malloc(sizeof(char *) * (my_tablen(cmd->env) + 2));
	int i = 0;

	while (cmd->env[i]) {
		new_env[i] = cmd->env[i];
		i++;
	}
	new_env[i] = path;
	new_env[i + 1] = 0;
	free(cmd->env);
	cmd->env = new_env;
}

int my_setenv(p_cmd *cmd, int i)
{
	char *path = my_strcat(cmd->tab[1], "=");

	if (check_setenv(cmd) == 84)
		return (0);
	while (cmd->env[i] && my_strcmp_to(path, cmd->env[i]) == 0)
		i++;
	if (cmd->env[i] == 0) {
		add_path_in_env(cmd, my_strcat(path, cmd->tab[2]));
		free(path);
		return (0);
	}
	free(cmd->env[i]);
	cmd->env[i] = my_strcat(path, cmd->tab[2]);
	free(path);
	return (0);
}

char **copy_env(char **env, int add)
{
	char **new_env = NULL;
	int i = 0;
	int u = 0;

	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1 + add));
	i = 0;
	while (env[i]) {
		u = 0;
		new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
		while (env[i][u]) {
			new_env[i][u] = env[i][u];
			u++;
		}
		new_env[i][u] = 0;
		i++;
	}
	new_env[i] = 0;
	return (new_env);
}

void my_put_env(char **env)
{
	int i = 0;

	if (env == NULL)
		return;
	while (env[i]) {
		my_put_str(env[i]);
		my_putchar('\n');
		i++;
	}
}
