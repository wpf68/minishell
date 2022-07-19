/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:53:13 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 14:40:32 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write (fd, (char *)s, ft_strlen(s));
}

/*

Prototype
void ft_putstr_fd(char *s, int fd);

Parametres
s: La chaîne de caractères à écrire.
fd: Le descripteur de fichier sur lequel Aucune

Fonctions externes autorisees
write

Description
Écrit la chaîne de caractères ’s’ sur le descripteur de fichier donné.

*/
