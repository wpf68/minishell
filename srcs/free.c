/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:44:29 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/28 08:13:58 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(t_setting *set)
{
	int	i;
	int	j;

	if (set->command)
		free(set->command);
	i = -1;
	while (set->cmd_shell[++i])
	{
		free(set->cmd_shell[i]);
		j = -1;
		while (set->comd_arg[i][++j])
			free(set->comd_arg[i][j]);
		free(set->comd_arg[i]);
	}
	free(set->cmd_shell);
	free(set->path_prompt);
	set->path_prompt = NULL;
}

void	ft_free_env(t_setting *set)
{
	int	i;

	i = -1;
	while (set->var_envp[++i])
		free(set->var_envp[i]);
	free(set->var_envp);
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
