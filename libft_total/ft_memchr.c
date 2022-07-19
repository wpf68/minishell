/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:58:58 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 16:14:39 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned long int n)
{
	char	*str;
	char	*str_end;

	str = (char *)s;
	str_end = str + n;
	while (str < str_end)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
/*
void *memchr(const void *s, int c, size_t n);

La fonction memchr() examine les n premiers octets 
de la zone mémoire pointée par s à la recherche du 
caractère c. Le premier octet correspondant à c 
(interprété comme un unsigned char) arrête l'opération.

Les fonctions memchr() et memrchr() renvoient un pointeur 
sur l'octet correspondant, ou NULL si le caractère n'est 
pas présent dans la zone de mémoire concernée. 
*/
