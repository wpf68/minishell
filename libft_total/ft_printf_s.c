/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:00:23 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 14:19:16 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_s(va_list ap, int *i)
{
	char	*tab;

	tab = va_arg(ap, char *);
	if (!tab)
	{
		*i = *i + 6;
		write(1, "(null)", 6);
		return ;
	}
	ft_putstr_fd(tab, 1);
	*i = *i + ft_strlen(tab);
}
