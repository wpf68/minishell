/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:44:17 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/27 15:22:59 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned long int nb, unsigned long int size)
{
	void	*p;

	p = NULL;
	p = malloc(size * nb);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nb * size);
	return (p);
}
/*
void *calloc(size_t nmemb, size_t size);

calloc() alloue la mémoire nécessaire pour un tableau de nmemb éléments de 
taille size octets, et renvoie un pointeur vers la mémoire allouée. Cette 
zone est remplie avec des zéros. Si nmemb ou size vaut 0, calloc() renvoie 
soit NULL, soit un pointeur unique qui pourra être passé ultérieurement à 
free() avec succès.
*/
