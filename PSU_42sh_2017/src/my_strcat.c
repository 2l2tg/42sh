/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** c file
*/

#include <stdlib.h>

int my_strlen(char *);

char *my_strcat_sep(char *str1, char *str2)
{
	int i = my_strlen(str1);
	int u = my_strlen(str2);
	char *res = malloc(sizeof(char) * (i + u + 2));

	i = 0;
	while (str1 && str1[i]) {
		res[i] = str1[i];
		i++;
	}
	res[i] = '/';
	i++;
	u = 0;
	while (str2 && str2[u]) {
		res[i] = str2[u];
		u++;
		i++;
	}
	res[i] = 0;
	return (res);
}

char *my_strcat(char *str1, char *str2)
{
	int i = my_strlen(str1);
	int u = my_strlen(str2);
	char *res = malloc(sizeof(char) * (i + u + 1));

	i = 0;
	while (str1 && str1[i]) {
		res[i] = str1[i];
		i++;
	}
	u = 0;
	while (str2 && str2[u]) {
		res[i] = str2[u];
		u++;
		i++;
	}
	res[i] = 0;
	return (res);
}
