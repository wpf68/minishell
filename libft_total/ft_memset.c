/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:28:30 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 16:03:16 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned long int n)
{
	unsigned long int	i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*
 
void *memset (void *s, int c, size_t n);
La fonction memset() remplit les n premiers octets de la zone mémoire pointée 
par s avec l'octet c.  
La fonction memset() renvoie un pointeur sur la zone mémoire s.  

*/
