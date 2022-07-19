/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_char_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:36:33 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 14:25:28 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_char_tab(char *tab)
{
	unsigned int	i;
	long int		len;
	char			c;

	i = 0;
	len = ft_strlen(tab);
	while (i < len / 2)
	{
		c = tab[i];
		tab[i] = tab[(len - 1) - i];
		tab[(len - 1) - i] = c;
		i++;
	}
}
