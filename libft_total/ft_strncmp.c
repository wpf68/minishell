/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:20:08 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/27 12:18:01 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned long int n)
{
	unsigned long int	i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] - s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
int strncmp(const char *s1, const char *s2, size_t n);

La fonction strcmp() compare les deux chaînes s1 et s2. Elle renvoie un 
entier négatif, nul, ou positif, si s1 est respectivement inférieure, 
égale ou supérieure à s2.
La fonction strncmp() est identique sauf qu'elle ne compare que les n (au 
plus) premiers caractères de s1 et s2.  

Les fonctions strcmp() et strncmp() renvoient un entier inférieur, égal 
ou supérieur à zéro si s1 (ou ses n premiers octets) est respectivement 
inférieure, égale ou supérieure à s2.  
*/
