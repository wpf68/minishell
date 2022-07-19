/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:04:07 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 13:06:51 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*src;

	src = (char *)s;
	ptr = malloc(sizeof(char) * ((ft_strlen(src)) + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, src, (ft_strlen(src) + 1));
	return (ptr);
}

/*
char *strdup(const char *s);

La fonction strdup() renvoie un pointeur sur une nouvelle chaîne de 
caractères qui est dupliquée depuis s. La mémoire occupée par cette 
nouvelle chaîne est obtenue en appelant malloc(3), et peut (doit) donc 
être libérée avec free(3).

VALEUR RENVOYÉE
La fonction strdup() renvoie un pointeur sur la chaîne dupliquée, ou 
NULL s'il n'y avait pas assez de mémoire.  
*/
