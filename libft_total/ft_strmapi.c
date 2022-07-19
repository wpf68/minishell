/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:17:12 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 13:19:38 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*tab;
	unsigned long int	len;
	unsigned long int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

/*
Prototype 
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

Paramètres 
s: La chaîne de caractères sur laquelle itérer.
f: La fonction à appliquer à chaque caractère.

Valeur de retour 
La chaîne de caractères résultant des applications successives de ’f’.
Retourne NULL si l’allocation échoue.

Fonctions externes autorisées
malloc

Description 
Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères passée en argument pour créer
une nouvelle chaîne de caractères (avec malloc(3))
résultant des applications successives de ’f’.

*/
