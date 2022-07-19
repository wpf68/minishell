/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:34:20 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 16:14:40 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_toupper_print(char c)
{
	if (ft_isascii(c) && c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
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
