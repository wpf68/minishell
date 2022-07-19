/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:28:13 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/27 11:20:05 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s)
	{
		if (*s == c)
			result = (char *)s;
		s++;
	}
	if (*s == c)
		result = (char *)s;
	return (result);
}

/*
char *strchr(const char *s, int c);
La fonction strchr() renvoie un pointeur sur la première occurrence du 
caractère c dans la chaîne s.

char *strrchr(const char *s, int c);
La fonction strrchr() renvoie un pointeur sur la dernière occurrence du
 caractère c dans la chaîne s.

Les fonctions strchr() et strrchr() renvoient un pointeur sur le caractère 
correspondant, ou NULL si le caractère n'a pas été trouvé.
*/
