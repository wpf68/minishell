/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:40:33 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 16:04:22 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned long int n)
{
	unsigned long int	i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
 
void bzero(void *s, size_t n);
La fonction bzero() met à 0 (octets contenant « \0 ») les n premiers octets 
du bloc pointé par s.   
 Cette fonction est déconseillée  utilisez memset(3) dans 
 les nouveaux programmes.  

*/
