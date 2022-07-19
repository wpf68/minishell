/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:29:01 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/28 15:58:20 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		while (set[j] == s1[i] && s1[i])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

static size_t	ft_end(size_t l1, const char *s1, const char *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		while (set[j] == s1[l1])
		{
			l1--;
			j = 0;
		}
		j++;
	}
	return (l1 + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned long int	l_s1;
	unsigned long int	start;
	size_t				i;
	char				*tab;

	if (!s1 || !set)
		return (NULL);
	l_s1 = ft_strlen((char *)s1);
	start = ft_start(s1, set);
	if (start == l_s1)
		return (tab = ft_calloc(1, 1));
	i = ft_end(l_s1 - 1, s1, set);
	tab = ((char *)malloc(sizeof(char) * (i - start + 1)));
	if (!tab)
		return (NULL);
	ft_memcpy(tab, (s1 + start), (i - start));
	tab[i - start] = '\0';
	return (tab);
}

/*
Prototype 
char *ft_strtrim(char const *s1, char const *set);

Paramètres 
s1: La chaîne de caractères à trimmer.
set: Le set de référence de caractères à trimmer.

Valeur de retour 
La chaîne de caractères trimmée.
NULL si l’allocation échoue.

Fonctions externes autorisées
malloc

Description 
Alloue (avec malloc(3)) et retourne une copie de
la chaîne ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaîne de
caractères.

test 6261
*/
