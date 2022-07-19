/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:15:03 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 17:17:45 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned long int n)
{
	unsigned long int	i;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	if (dest > src && n != 0)
	{
		n--;
		while (n > 0)
		{
			*(char *)(dest + n) = *(char *)(src + n);
			n--;
		}
			*(char *)(dest + n) = *(char *)(src + n);
	}
	else
	{
		while (i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

/*
void *memmove(void *dest, const void *src, size_t n);
La fonction memmove() copie n octets depuis la zone mémoire src 
vers la zone mémoire dest. Les deux zones peuvent se chevaucher : 
la copie se passe comme si les octets de src étaient d'abord copiés 
dans une zone temporaire qui ne chevauche ni src ni dest, et les 
octets sont ensuite copiés de la zone temporaire vers dest.  

La fonction memmove() renvoie un pointeur sur dest.    
*/
