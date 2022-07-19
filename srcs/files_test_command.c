/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_test_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:30:25 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:31:30 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_test_command_2(t_setting *set, int i, char *test_path_cmd)
{
	int		j;
	char	*test_path;

	set->split = ft_split(set->path_env, ':');
	j = -1;
	while (set->split[++j])
	{
		test_path = ft_strjoin(set->split[j], "/");
		test_path_cmd = ft_strjoin(test_path, set->comd_arg[i][0]);
		free(test_path);
		if (access(test_path_cmd, X_OK) == 0)
		{
			ft_free_split(set->split);
			free(test_path_cmd);
			g_signale.status = 0;
			return (0);
		}
	}
	return (1);
}

static int	ft_test_command_3(t_setting *set, int i)
{
	if (access(set->comd_arg[i][0], X_OK) == 0)
	{
		g_signale.status = 0;
		return (0);
	}
	return (1);
}

int	ft_test_command(t_setting *set, int i)
{
	char	*test_path_cmd;

	test_path_cmd = NULL;
	if (set->comd_arg[i][0][0] == '/')
	{
		if (!ft_test_command_3(set, i))
			return (0);
	}	
	else if (set->path_env)
	{
		if (!ft_test_command_2(set, i, test_path_cmd))
			return (0);
	}
	g_signale.status = 127;
	printf("%s: command not found\n", set->comd_arg[i][0]);
	return (1);
}
