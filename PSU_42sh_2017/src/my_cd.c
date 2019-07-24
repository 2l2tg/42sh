/*
** EPITECH PROJECT, 2018
** my_cd
** File description:
** c file
*/

#include "mysh.h"

int change_pwd(char **env)
{
	char *path = NULL;
	char *path_dir = NULL;
	int i = 0;

	while (env[i] && my_strcmp_to("PWD=", env[i]) == 0)
		i++;
	if (env[i] && my_strcmp_to("PWD=", env[i])) {
		path_dir = getcwd(path_dir, 0);
		if (path_dir == NULL)
			return (0);
		path = my_strcat("PWD=", path_dir);
		free(env[i]);
		env[i] = path;
		free(path_dir);
	}
	return (0);
}

int my_cd_pwd(char **env)
{
	char *home;
	int i = 0;
	int u = 4;

	while (env[i] && my_strcmp_to("PWD=", env[i]) == 0)
		i++;
	if (env[i] && my_strcmp_to("PWD=", env[i])) {
		home = malloc(sizeof(char) * (my_strlen(env[i]) - 4 + 1));
		while (env[i][u]) {
			home[u - 4] = env[i][u];
			u++;
		}
		home[u - 4] = 0;
		change_pwd(env);
		chdir(home);
		free(home);
	}
	return (0);
}

int my_cd_home(char **env)
{
	char *home;
	int i = 0;
	int u = 5;

	change_pwd(env);
	while (env[i] && my_strcmp_to("HOME=", env[i]) == 0)
		i++;
	if (env[i] && my_strcmp_to("HOME=", env[i])) {
		home = malloc(sizeof(char) * (my_strlen(env[i]) - 5 + 1));
		while (env[i][u]) {
			home[u - 5] = env[i][u];
			u++;
		}
		home[u - 5] = 0;
		chdir(home);
		free(home);
	}
	return (0);
}

int my_cd_empty(char **tab, char **env)
{
	DIR *dir = NULL;
	int fd = 0;

	if ((dir = opendir(tab[1])) != NULL) {
		change_pwd(env);
		chdir(tab[1]);
		closedir(dir);
	} else if ((fd = open(tab[1], O_RDONLY)) > 0) {
		my_put_str(tab[1]);
		my_put_str(": Not a directory.\n");
		close(fd);
	} else {
		my_put_str(tab[1]);
		my_put_str(": No such file or directory.\n");
	}
	return (0);
}

int my_cd(char **tab, char **env)
{
	if (tab[1] == NULL)
		my_cd_home(env);
	else if (tab[1][0] == '-')
		my_cd_pwd(env);
	else if (tab[1])
		my_cd_empty(tab, env);
	return (0);
}
