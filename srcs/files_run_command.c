/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_run_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:06:21 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/07/04 11:29:42 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_run_command_2(t_setting *set)
{
	int	i;

	i = -1;
	while (set->cmd_shell[++i])
	{
		if (ft_test_builtins(set, i))
		{
			ft_test_command(set, i);
			if (g_signale.status)
				return (1);
		}
	}
	return (0);
}

static void	ft_run_command_end(t_setting *set)
{
	int	j;

	j = 2;
	while (++j < set->nb_command + 4)
		close(j);
	if (set->name_redirect)
	{
		free(set->name_redirect);
		set->name_redirect = NULL;
		close(set->fd);
	}
	set->redirect = 0;
}

void	ft_run_command(t_setting *set)
{
	int	j;

	if (ft_run_command_2(set))
		return ;
	set->in = 0;
	j = -1;
	while (set->cmd_shell[++j])
	{
		set->redirect = 0;
		if (ft_redirect(set, j) || ft_redirect_in(set, j))
			break ;
		pipe(set->pdes);
		g_signale.child = fork();
		if (g_signale.child == -1)
			ft_error("error fork\n", 1);
		if (g_signale.child == 0)
			ft_child(set, j);
		else
			ft_parent(set, j);
	}
	ft_run_command_end(set);
}
