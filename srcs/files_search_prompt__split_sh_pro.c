/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_search_prompt__split_sh_pro.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:24:31 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:25:46 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_search_prompt_color(t_setting *set)
{
	char	*temp;

	set->path_prompt = ft_strjoin("", "\033[1;32m");
	temp = set->path_prompt;
	set->path_prompt = ft_strjoin(temp, set->path_begin);
	free(temp);
	temp = set->path_prompt;
	set->path_prompt = ft_strjoin(temp, "@minishell\033[33m");
	free(temp);
	temp = set->path_prompt;
	set->path_prompt = ft_strjoin(temp, set->path_end);
	free(temp);
	temp = set->path_prompt;
	set->path_prompt = ft_strjoin(temp, "\033[37m $ \033[0m");
	free(temp);
}

void	ft_search_prompt(t_setting *set)
{
	char	*temp;

	if (set->color % 2)
		ft_search_prompt_color(set);
	else
	{
		set->path_prompt = ft_strjoin("", "");
		temp = set->path_prompt;
		set->path_prompt = ft_strjoin(temp, set->path_begin);
		free(temp);
		temp = set->path_prompt;
		set->path_prompt = ft_strjoin(temp, "@minishell");
		free(temp);
		temp = set->path_prompt;
		set->path_prompt = ft_strjoin(temp, set->path_end);
		free(temp);
		temp = set->path_prompt;
		set->path_prompt = ft_strjoin(temp, " $ ");
		free(temp);
	}
}

int	ft_split_shell(t_setting *set)
{
	int	i;

	i = -1;
	while (++i < set->nb_command)
	{
		set->comd_arg[i] = ft_split_quote(set, set->cmd_shell[i], ' ');
		if (set->comd_arg[i] == NULL)
		{
			set->error_quote = 0;
			break ;
		}
	}
	set->comd_arg[i] = NULL;
	return (0);
}

void	ft_split_prompt(t_setting *set)
{
	set->cmd_shell = ft_split_quote(set, set->command, '|');
	if (set->cmd_shell == NULL)
	{
		set->error_quote = 0;
		return ;
	}
	set->nb_command = 0;
	while (set->cmd_shell[set->nb_command])
		set->nb_command += 1;
}
