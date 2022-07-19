/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:59:35 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 14:17:58 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_d_i(va_list ap, int *i)
{
	char	*tab;

	tab = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(tab, 1);
	*i = *i + ft_strlen(tab);
	free(tab);
}
