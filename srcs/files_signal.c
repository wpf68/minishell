/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:26:02 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/07/04 11:30:20 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_signal_2(void)
{	
	wait(NULL);
	write(STDERR_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}

static void	ft_signal_3(void)
{	
	wait(NULL);
	write(STDERR_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	ft_signal(int sig)
{
	g_signale.status = 128 + sig;
	if (sig == SIGINT)
	{
		if (g_signale.child && kill(g_signale.child, SIGTERM) == 0)
			ft_signal_2();
		else
		{	
			write(STDERR_FILENO, "\n", 1);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
	}
	if (sig == SIGQUIT)
	{
		if (g_signale.child && kill(g_signale.child, SIGTERM) == 0)
			ft_signal_3();
		else
		{
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
	}
}
