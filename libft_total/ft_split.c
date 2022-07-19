/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:56:10 by pwolff            #+#    #+#             */
/*   Updated: 2022/06/29 08:38:57 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_part(const char *tab, char c)
{
	int	part;
	int	test;

	part = 0;
	test = 0;
	while (*tab)
	{
		if (*tab != c && test == 0)
		{
			part++;
			test = 1;
		}
		else if (*tab == c)
			test = 0;
		tab++;
	}
	return (part);
}

static char	*ft_tab(const char *str, int start, int finish)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		tab[i++] = str[start++];
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((ft_part(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_tab(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

/*Prototype 
char **ft_split(char const *s, char c);

Paramètres 
s: La chaîne de caractères à découper.
c: Le caractère délimiteur.

Valeur de retour 
Le tableau de nouvelles chaînes de caractères
résultant du découpage.
NULL si l’allocation échoue.

Fonctions externes autorisées
malloc, free

Description 
Alloue (avec malloc(3)) et retourne un tableau
de chaînes de caractères obtenu en séparant ’s’ à
l’aide du caractère ’c’, utilisé comme délimiteur.
Le tableau doit être terminé par NULL.

*/
