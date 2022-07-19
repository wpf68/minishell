/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_rm_and_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:50:15 by pwolff            #+#    #+#             */
/*   Updated: 2022/06/27 17:00:42 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_rm_heredoc(void)
{
	int		child;
	char	*args[3];

	child = fork();
	if (child == -1)
		ft_error("error fork rm\n", 1);
	if (child == 0)
	{
		args[0] = "rm";
		args[1] = ".heredoc";
		args[2] = NULL;
		execve("/bin/rm", args, NULL);
		exit(0);
	}
	else
	{
		wait(NULL);
	}
}

void	ft_rm_debug(void)
{
	int		child;
	char	*args[3];

	child = fork();
	if (child == -1)
		ft_error("error fork rm\n", 1);
	if (child == 0)
	{
		args[0] = "rm";
		args[1] = ".xxooxxo";
		args[2] = NULL;
		execve("/bin/rm", args, NULL);
		exit(0);
	}
	else
	{
		wait(NULL);
	}
}

void	ft_create_var_error(t_setting *set)
{
	char	*str;
	int		temp;

	set->comd_arg[0] = malloc(sizeof(set->comd_arg[0]) * 3);
	if (set->comd_arg[0] == NULL)
		ft_error("error malloc \n", 1);
	set->comd_arg[0][0] = NULL;
	set->comd_arg[0][1] = ft_strjoin("", "?=");
	str = set->comd_arg[0][1];
	set->comd_arg[0][1] = ft_strjoin(str, ft_itoa(g_signale.status));
	free(str);
	set->comd_arg[0][2] = NULL;
	temp = g_signale.status;
	ft_export(set, 0);
	g_signale.status = temp;
	free(set->comd_arg[0][1]);
	free(set->comd_arg[0]);
}
