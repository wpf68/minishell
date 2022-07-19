/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:27:02 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 11:06:27 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_command_2(t_setting *set)
{
	char	*str;

	if (set->debug)
	{
		set->command = readline(set->path_prompt);
		if (set->command == NULL)
			ft_exit(set, -1);
		if (ft_strlen(set->command) > 1500)
		{
			printf("WARNING ! line too long\n");
			return (1);
		}
		if (*set->command)
			add_history(set->command);
	}
	else
	{
		str = "ls > .xxooxxo";
		set->command = ft_strdup(str);
	}
	return (0);
}

static int	ft_command_3(t_setting *set)
{
	int	i;
	int	test;

	i = 0;
	test = 1;
	while (set->command[i])
	{
		if (set->command[i] != ' ')
		{
			test = 0;
			i++;
			break ;
		}
		i++;
	}
	if (i == 0 || test)
		return (1);
	return (0);
}

int	ft_command(t_setting *set)
{
	struct sigaction	s1;

	s1.sa_flags = 0;
	s1.sa_handler = &ft_signal;
	sigaction(SIGINT, &s1, NULL);
	sigaction(SIGQUIT, &s1, NULL);
	set->command = NULL;
	if (ft_command_2(set))
		return (1);
	if (ft_command_3(set))
		return (1);
	set->error_quote = 1;
	ft_test_quote_dquote(set);
	if (set->error_quote)
		ft_split_prompt(set);
	if (set->error_quote)
		ft_split_shell(set);
	if (set->error_quote)
	{
		return (0);
	}
	if (set->error_quote == 0)
		printf("Error quote\n");
	return (1);
}
