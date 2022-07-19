/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:00:23 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/08 11:00:23 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_x(va_list ap, int *i, char c)
{
	unsigned int	pt;
	char			*tab_hex;
	unsigned int	j;

	tab_hex = NULL;
	pt = va_arg(ap, unsigned int);
	tab_hex = ft_hex_lower(pt);
	if (c == 'X')
	{
		j = 0;
		while (tab_hex[j])
		{
			tab_hex[j] = ft_toupper_print(tab_hex[j]);
			j++;
		}
	}
	ft_putstr_fd(tab_hex, 1);
	*i = *i + ft_strlen(tab_hex);
	free(tab_hex);
}
