/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:33:23 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 13:34:06 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isascii(c) && c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	return (c);
}

/*
int toupper(int c);
toupper() convertit la lettre c en majuscule si c'est possible.

int tolower(int c);
tolower() convertit la lettre c en minuscule si c'est possible.
 
Si c n'est ni une valeur unsigned char, ni EOF, le comportement de ces 
fonctions est imprévisible.

La valeur renvoyée est celle de la lettre convertie, ou bien c si la 
conversion n'était pas possible.  
*/
