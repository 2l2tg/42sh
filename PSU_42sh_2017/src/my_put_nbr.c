/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** c file
*/

int my_putchar(char);

void my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		my_put_nbr(nb / 10);
	my_putchar(48 + (nb % 10));
}
