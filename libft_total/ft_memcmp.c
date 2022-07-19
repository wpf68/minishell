/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:59:46 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 16:27:22 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned long int n)
{
	while (n)
	{
		if (*(char *)s1 != *(char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/*
int memcmp(const void *s1, const void *s2, size_t n);

La fonction memcmp() compare les n premiers octets des zones 
mémoire s1 et s2. Elle renvoie un entier inférieur, égal, ou 
supérieur à zéro, si s1 est respectivement inférieure, égale 
ou supérieur à s2.  

La fonction memcmp() renvoie un entier négatif, nul ou positif 
si les n premiers octets de s1 sont respectivement inférieurs, 
égaux ou supérieurs aux n premiers octets de s2.  
*/
