/*
** EPITECH PROJECT, 2018
** my_put_str
** File description:
** c file
*/

#include "mysh.h"

void my_put_str(char *str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (str[i]) {
		my_putchar(str[i]);
		i++;
	}
}

int my_put_ret(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i]) {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

void my_put_err(char *str)
{
	my_put_str(str);
}
