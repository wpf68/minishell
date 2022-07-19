/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:09:52 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/03 11:21:42 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = size;
	while (*dst)
	{
		dst++;
		if (j > 0)
			j--;
	}
	while (*src && j > 1)
	{
		*dst++ = *src++;
		j--;
	}
	*dst = '\0';
	if (size > dst_len)
		return (dst_len + src_len);
	return (size + src_len);
}

/*
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] && i < size)
		i++;
	while (src[k])
		k++;
	if (size == 0)
		return (i);
	if (i < size)
	{
		while ((j + i < size - 1) && src[j])
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (i + k);
}
*/
/*
size_t strlcat ( char *dst , const char *src , size_t size );
La fonction strlcat () ajoute la chaîne terminée par NUL src à la fin de dst.
Il ajoutera au plus size - strlen(dst) - 1 octets, terminant le 
résultat par NUL.

Les fonctions strlcpy () et strlcat () renvoient la longueur totale 
de la chaîne qu'elles ont tenté de créer. Pour strlcpy (), cela signifie la 
longueur de src . 
Pour strlcat (), cela signifie la longueur initiale de dst plus la longueur 
de src . Bien que cela puisse sembler quelque peu déroutant, cela a été fait 
pour simplifier la détection de troncature.
*/
