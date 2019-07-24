/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** c file
*/

int my_strlen(char *);

int my_strcmp(char *find, char *str)
{
	int i = 0;

	while (find[i] && str[i] && str[i] == find[i])
		i++;
	if (find[i] == 0 && (str[i] == 0 || str[i] == ' '))
		return (1);
	return (0);
}

int my_strcmp_to(char *find, char *str)
{
	int i = 0;

	while (find[i] && str[i] && str[i] == find[i])
		i++;
	if (find[i] == 0)
		return (1);
	return (0);
}
