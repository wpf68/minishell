/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:03:16 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 16:52:35 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
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
