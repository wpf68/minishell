/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:20:57 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/28 12:29:29 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, unsigned long int len)
{
	unsigned long int	i;
	unsigned long int	j;

	if (*(char *)s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (*(char *)(s1 + i) && i < len)
	{
		j = 0;
		while (*(char *)(s2 + j) == *(char *)(s1 + i + j) && (i + j) < len)
		{
			if (*(char *)(s2 + j + 1) == '\0')
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
char * strnstr(const char * s1, const char * s2, size_t len);

     Ce qui suit définit le pointeur ptr sur NULL, car seuls les 
	 4 premiers caractères de *largestring sont recherchés :

	   const char *largestring = "Foo Bar Baz";
	   const char *smallstring = "Bar";
	   char	*ptr;

	   ptr = strnstr(largestring, smallstring, 4)
	   
	   
Test : 3668;

*/
