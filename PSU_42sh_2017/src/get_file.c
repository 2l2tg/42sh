/*
** EPITECH PROJECT, 2018
** get_map
** File description:
** c file
*/

#include "mysh.h"

char *re_alloc(char *str, char c)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 2));
	int i = 0;

	while (str != NULL && str[i] != '\0') {
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (str != NULL)
		free(str);
	return (new);
}

char *get_file(int fd)
{
	int i = 0;
	int size = 0;
	char buff[1];
	char *str = NULL;

	while ((size = read(fd, buff, 1)) > 0) {
		str = re_alloc(str, buff[0]);
		i++;
	}
	if (str != NULL)
		str[i] = '\0';
	return (str);
}
