/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_interpreter_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:08:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/07/04 09:53:46 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	if_simple_quote(t_setting *set, int i, int j)
{
	int	k;

	k = 0;
	while (set->comd_arg[i][j][++k])
		set->comd_arg[i][j][k - 1] = set->comd_arg[i][j][k];
	set->comd_arg[i][j][k - 2] = '\0';
}

static void	if_double_quote_2(t_setting *set, int i, int j, char *new_var)
{
	int	m;

	m = 0;
	set->var = NULL;
	while (set->comd_arg[i][j][++set->k]
			&& set->comd_arg[i][j][set->k] != ' '
			&& set->comd_arg[i][j][set->k] != '\"' &&
			(ft_isalnum(set->comd_arg[i][j][set->k])
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

static void	if_double_quote(t_setting *set, int i, int j, char *new_var)
{
	new_var[0] = '\0';
	set->k = 0;
	set->l = 0;
	while (set->comd_arg[i][j][++set->k]
			&& set->comd_arg[i][j][set->k] != '\"')
	{
		if (set->comd_arg[i][j][set->k] != '$'
				|| (set->comd_arg[i][j][set->k] == '$'
				&& (set->comd_arg[i][j][set->k + 1] == ' '
				|| set->comd_arg[i][j][set->k + 1] == '\"')))
		{
			new_var[set->l++] = set->comd_arg[i][j][set->k];
			new_var[set->l] = '\0';
		}
		else
			if_double_quote_2(set, i, j, new_var);
	}
	free(set->comd_arg[i][j]);
	set->comd_arg[i][j] = ft_strjoin("", new_var);
}

void	ft_interpreter_quotes(t_setting *set)
{
	int		i;
	int		j;
	char	*new_var;

	i = -1;
	while (set->cmd_shell[++i])
	{
		j = -1;
		while (set->comd_arg[i][++j])
		{
			new_var = malloc(sizeof(new_var) * 4096);
			if (new_var == NULL)
				ft_error("Error malloc ft_interpreter", 1);
			if (set->comd_arg[i][j][0] == '\'')
				if_simple_quote(set, i, j);
			else if (set->comd_arg[i][j][0] == '\"')
				if_double_quote(set, i, j, new_var);
			else
				if_no_quote(set, i, j, new_var);
			free(new_var);
		}
	}
}
