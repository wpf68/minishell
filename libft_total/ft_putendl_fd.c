/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:26:20 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/28 15:06:38 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write (fd, (char *)s, ft_strlen(s));
		write (fd, "\n", 1);
	}
}
/*
 Prototype
 void ft_putendl_fd(char *s, int fd);

Parametres
s: La chaîne de caractères à écrire.
fd: Le descripteur de fichier sur lequel Aucune

Fonctions externes autorisees
write
  
Description
Écrit La chaîne de caractères ’s’ sur le descripteur de fichier donné 
suivie d’un retour à la ligne.

*/
