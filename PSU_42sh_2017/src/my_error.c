/*
** EPITECH PROJECT, 2018
** my error
** File description:
** c file
*/

#include "mysh.h"

int my_error(char *str)
{
	if (str[0] == '>' || str[0] == '<')
		my_put_str("Missing name for redirect.\n");
	else if (str[0] == '|' || str[0] == '&')
		my_put_str("Invalid null command.\n");
	return (1);
}
