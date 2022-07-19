/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:32:25 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 14:39:58 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*

Prototype
void ft_putchar_fd(char c, int fd);

Parametres
c: Le caractère à écrire.
fd: Le descripteur de fichier sur lequel écrire.

Valeur de retour
Aucune

Fonctions externes autorisees
write

Description
Écrit le caractère ’c’ sur le descripteur de fichier donné.

test 7262

*/
