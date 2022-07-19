/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:31:48 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/27 15:12:08 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		tab = ft_calloc(1, 1);
		return (tab);
	}
	tab = (char *)(malloc(sizeof(char) * (len + 1)));
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, len + 1);
	i = 0;
	while (i < len && s[start + i])
	{
		tab[i] = s[start + i];
		i++;
	}
	return (tab);
}

/*
Prototype 
char *ft_substr(char const *s, unsigned int start, size_t len);

Paramètres 
s: La chaîne de laquelle extraire la nouvelle chaîne.
start: L’index de début de la nouvelle chaîne dans la chaîne ’s’.
len: La taille maximale de la nouvelle chaîne.

Valeur de retour 
La nouvelle chaîne de caractères. NULL si l’allocation échoue.

Fonctions externes autorisées
malloc

Description 
Alloue (avec malloc(3)) et retourne une chaîne de caractères issue 
de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et a pour taille 
maximale ’len’.
*/
