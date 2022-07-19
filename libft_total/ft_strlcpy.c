/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:12:16 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/27 12:55:29 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < (size - 1) && src[i] != '\0' && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

/*
size_t strlcpy ( char *dst , const char *src , size_t size );
La fonction strlcpy () copie jusqu'à taille - 1 caractères de la chaîne src 
terminée par NUL vers dst , terminant le résultat par NUL.

Les fonctions strlcpy () et strlcat () renvoient la longueur totale 
de la chaîne qu'elles ont tenté de créer. Pour strlcpy (), cela signifie 
la longueur de src . Pour strlcat (), cela signifie la longueur initiale 
de dst plus la longueur de src . Bien que cela puisse sembler quelque peu 
déroutant, cela a été fait pour simplifier la détection de troncature.

*/
