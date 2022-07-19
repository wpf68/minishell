/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_test_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:28:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:28:54 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_test_dquote(t_setting *set, int *i)
{
	set->dq = 0;
	*i += 1;
	while (set->command[*i] != '"' && set->command[*i])
		*i += 1;
	if (set->command[*i] == '"')
		set->dq = 1;
}

void	ft_test_quote_dquote(t_setting *set)
{
	int	i;

	i = -1;
	set->dq = 1;
	set->q = 1;
	while (set->command[++i])
	{
		if (set->command[i] == '"')
			ft_test_dquote(set, &i);
		else if (set->command[i] == '\'')
		{
			set->q = 0;
			i++;
			while (set->command[i] != '\'' && set->command[i])
				i++;
			if (set->command[i] == '\'')
				set->q = 1;
		}
	}
	if (set->dq == 0 || set->q == 0)
		set->error_quote = 0;
}
