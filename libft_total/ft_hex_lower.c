/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:36:33 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/08 10:47:59 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_tab_hex(unsigned int nb)
{
	unsigned int	i;
	char			*tab_hex;

	i = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		i++;
	}
	tab_hex = (char *)malloc(sizeof(char) * (i + 1));
	if (tab_hex == NULL)
		return (NULL);
	tab_hex[i] = '\0';
	if (nb == 0)
		tab_hex[0] = '0';
	return (tab_hex);
}

char	*ft_hex_lower(unsigned int nb)
{
	char			c;
	unsigned int	mod;
	unsigned int	i;
	char			*tab_hex;

	i = 0;
	tab_hex = ft_tab_hex(nb);
	while (nb)
	{
		mod = nb % 16;
		if (mod < 10)
			c = mod + '0';
		else
			c = (mod - 10) + 'a';
		tab_hex[i] = c;
		nb = nb / 16;
		i++;
	}
	if (tab_hex[1] != '\0')
		ft_rev_char_tab(tab_hex);
	return (tab_hex);
}

/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.
-------------------------------------------------- ---------------------------

Ecrire un programme qui prend un nombre positif (ou nul) exprimé en base 10,
et l'affiche en base 16 (lettres minuscules) suivie d'une nouvelle ligne.

Si le nombre de paramètres n'est pas 1, le programme affiche une nouvelle 
ligne.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/
