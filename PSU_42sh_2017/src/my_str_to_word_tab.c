/*
** EPITECH PROJECT, 2018
** my_str_to_word_tab
** File description:
** c file
*/

#include <stdlib.h>

int word_len(char *str, int pos)
{
	int i = 0;

	while (str[pos + i] && str[pos + i] != ' ' && str[pos + i] != ':')
		i++;
	return (i);
}

int word_count(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i] == ' ' || str[i] == ':' || str[i] == '\t')
		i++;
	while (str[i]) {
		while (str[i] && str[i] != ' ' && str[i] != ':'
		&& str[i] != '\t')
			i++;
		while (str[i] == ' ' || str[i] == ':' || str[i] == '\t')
			i++;
		res++;
	}
	return (res);
}

char **my_str_to_word_tab(char *str, int i)
{
	char **res = NULL;
	int u = 0;
	int y = 0;

	res = malloc(sizeof(char *) * (word_count(str) + 1));
	while (str[i] == ' ' || str[i] == ':' || str[i] == '\t')
		i++;
	while (str[i]) {
		y = 0;
		res[u] = malloc(sizeof(char) * (word_len(str, i) + 1));
		while (str[i] && str[i] != ' ' && str[i] != ':'
		&& str[i] != '\t')
			res[u][y++] = str[i++];
		res[u][y] = 0;
		while (str[i] == ' ' || str[i] == ':' || str[i] == '\t')
			i++;
		u++;
	}
	res[u] = 0;
	return (res);
}

void free_tab(char **tab)
{
	int i = 0;

	if (tab == NULL)
		return;
	while (tab[i] != 0) {
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
