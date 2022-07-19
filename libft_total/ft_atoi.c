/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:30:43 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/01 12:09:30 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static long	ft_test_max_min(unsigned long long nb, int sign)
{
//	printf("\nnb = %ld  sign = %d\n", nb, sign);
	if (nb > 9223372036854775807 && sign == -1)
		return (-1);
	if (nb >= 9223372036854775807 && signe == 1) 
		return (0);
	return (nb);
}
*/
long long	ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					sign;
	size_t				i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = 10 * nb + str[i] - '0';
		i++;
	}
	if (nb > 9223372036854775807 && sign == -1)
		return (0);
	if (nb >= 9223372036854775807 && sign == 1)
		return (-1);
	return (nb * sign);
}

/*
int atoi(const char *nptr);

La fonction atoi() convertit le début de la chaîne 
pointée par nptr en entier de type int 
VALEUR RENVOYÉE
Le résultat de la conversion.  
*/
