/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:16:11 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/03 11:19:39 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = n * (-1);
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}
/*
static void	ft_putnbr_print(int n, int fd, char c)
{
	if (n == 0)
		return ;
	c = n % 10 + '0';
	ft_putnbr_print (n / 10, fd, c);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = '0';
	if (n == 0)
		write (fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 2147483647)
		write(fd, "2147483647", 10);
	else
		ft_putnbr_print(n, fd, c);
}
*/
/*
Prototype
void ft_putnbr_fd(int n, int fd);

Parametres
n: L’entier à écrire.
fd: Le descripteur de fichier sur lequel Aucune

Fonctions externes autorisees
write

Description
Écrit l’entier ’n’ sur le descripteur de donné.
*/
