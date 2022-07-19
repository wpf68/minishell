/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:07:53 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 13:09:17 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	tab = NULL;
	tab = (char *)(malloc(sizeof(char) * size));
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, size);
	size = ft_strlen((char *)s1);
	ft_memcpy(tab, (char *)s1, size);
	ft_memcpy(&tab[size], (char *)s2, ft_strlen((char *)s2));
	return (tab);
}

/*
Prototype 
char *ft_strjoin(char const *s1, char const *s2);

Paramètres 
s1: La chaîne de caractères préfixe.
s2: La chaîne de caractères suffixe.

Valeur de retour 
La nouvelle chaîne de caractères.

NULL si l’allocation échoue.

Fonctions externes autorisées
malloc

Description 
Alloue (avec malloc(3)) et retourne une nouvelle chaîne, résultat 
de la concaténation de s1 et s2.
*/
