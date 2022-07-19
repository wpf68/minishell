/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_interpreter_quotes_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:08:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/07/04 11:28:16 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	if_no_quote_2(t_setting *set, int i, int j, char *new_var)
{
	int	m;

	m = 0;
	set->var = NULL;
	while (set->comd_arg[i][j][++set->k]
			&& set->comd_arg[i][j][set->k] != ' '
			&& (ft_isalnum(set->comd_arg[i][j][set->k])
			|| set->comd_arg[i][j][set->k] == '_'
			|| set->comd_arg[i][j][set->k] == '?'))
		set->temp[m++] = set->comd_arg[i][j][set->k];
	set->temp[m] = '\0';
	set->k--;
	set->var = ft_look_for_var(set, set->temp);
	if (set->var)
	{
		m = -1;
		while (set->var[++m])
			new_var[set->l++] = set->var[m];
		new_var[set->l] = '\0';
		free(set->var);
	}
}

void	if_no_quote(t_setting *set, int i, int j, char *new_var)
{
	new_var[0] = '\0';
	set->k = -1;
	set->l = 0;
	while (set->comd_arg[i][j][++set->k])
	{
		if (set->comd_arg[i][j][set->k] != '$'
				|| (set->comd_arg[i][j][set->k] == '$'
				&& set->comd_arg[i][j][set->k + 1] == '\0'))
		{
			new_var[set->l++] = set->comd_arg[i][j][set->k];
			new_var[set->l] = '\0';
		}
		else
			if_no_quote_2(set, i, j, new_var);
	}
	free(set->comd_arg[i][j]);
	set->comd_arg[i][j] = ft_strjoin("", new_var);
}
