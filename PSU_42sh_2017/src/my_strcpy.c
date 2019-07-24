/*
** EPITECH PROJECT, 2018
** my strcpy
** File description:
** c file
*/

#include "mysh.h"

char *my_strcpy(char *str)
{
	int i = 0;
	char *new = NULL;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (my_strlen(str) + 1));
	while (str[i]) {
		new[i] = str[i];
		i++;
	}
	new[i] = str[i];
	return (new);
}
