/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** c file
*/

#include "mysh.h"

int my_strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int my_tablen(char **tab)
{
	int i = 0;

	if (tab == NULL)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int my_strlen_to(char *str, int i, char to)
{
	int res = 0;

	if (my_strlen(str) < i)
		return (0);
	while (str[res + i] && str[res + i] != to)
		res++;
	return (res);
}
