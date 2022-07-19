/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:26:16 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 14:41:06 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned long int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
size_t strlen(const char *s);
La fonction strlen() calcule la longueur de la chaîne de caractères s, 
sans compter l'octet nul « \0 » final.  
La fonction strlen() renvoie le nombre de caractères dans la chaîne s.  
*/
