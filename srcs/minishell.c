/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:04:00 by pwolff            #+#    #+#             */
/*   Updated: 2022/07/04 11:31:05 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_if_command(t_setting *set)
{
	ft_interpreter_quotes(set);
	ft_run_command(set);
	if (!set->debug)
	{
		set->debug = 1;
		ft_rm_debug();
	}
	ft_free(set);
}

static void	ft_if_no_command(t_setting *set)
{
	if (set->command)
		free(set->command);
}

static void	ft_reinitial_prompt(t_setting *set)
{
	ft_name_minishell(set);
	ft_search_prompt(set);
	ft_create_var_error(set);
	if (set->double_arrow)
	{
		set->double_arrow = 0;
		ft_rm_heredoc();
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_setting	set;

	(void)argc;
	(void)argv;
	ft_presentation();
	ft_init(&set, envp);
	ft_create_var_error(&set);
	while (set.on_off)
	{
		if (!ft_command(&set) && set.error_quote)
			ft_if_command(&set);
		else
			ft_if_no_command(&set);
		ft_reinitial_prompt(&set);
	}
	return (0);
}
