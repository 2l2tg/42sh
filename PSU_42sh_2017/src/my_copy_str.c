/*
** EPITECH PROJECT, 2018
** my_copy_str
** File description:
** c file
*/

#include <stdlib.h>

int my_strlen(char *);

char *my_copy_str(char *str)
{
	int i = 0;
	char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (str == NULL)
		return (NULL);
	while (str[i]) {
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
