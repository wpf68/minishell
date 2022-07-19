/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:00:34 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 16:06:28 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned long int n)
{
	unsigned long int	i;
	char				*first;
	char				*secound;

	if (dest == NULL && src == NULL)
		return (dest);
	first = (char *)dest;
	secound = (char *)src;
	i = 0;
	while (i < n)
	{
		first[i] = secound[i];
		i++;
	}
	return (dest);
}

/*
void *memcpy(void *dest, const void *src, size_t n);
La fonction memcpy() copie n octets depuis la zone mémoire src vers 
la zone mémoire dest. Les deux zones ne doivent pas se chevaucher. 
Si c'est le cas, utilisez plutôt memmove(3).  

La fonction memcpy() renvoie un pointeur sur dest. 

//	while (i < n && first[i] && secound[i]) si non verif par user
*/
