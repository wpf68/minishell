/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:00:23 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 15:14:58 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_p(va_list ap, int *i)
{
	unsigned long int	pt;
	char				*tab_hex;

	tab_hex = NULL;
	pt = (unsigned long int)va_arg(ap, void *);
	if (pt == 0)
	{
		*i = *i + 3;
		write(1, "0x0", 3);
		return ;
	}
	tab_hex = ft_hex_lower_long(pt, tab_hex);
	write(1, "0x", 2);
	ft_putstr_fd(tab_hex, 1);
	*i = *i + ft_strlen(tab_hex) + 2;
	free(tab_hex);
}

/*
 * "(nil)" sur PC
 * "0x0"  sur Mac
 */
