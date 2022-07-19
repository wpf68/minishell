/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_path_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:29:07 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:29:58 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_path_cmd_2(t_setting *set, int i)
{
	char	*test_path;
	char	*test_path_cmd;
	int		j;

	j = -1;
	while (set->split[++j])
	{
		test_path = ft_strjoin(set->split[j], "/");
		test_path_cmd = ft_strjoin(test_path, set->comd_arg[i][0]);
		free(test_path);
		if (access(test_path_cmd, X_OK) == 0)
		{
			ft_free_split(set->split);
			return (test_path_cmd);
		}
	}
	return (NULL);
}

char	*ft_path_cmd(t_setting *set, int i)
{
	char	*test_path_cmd;

	if (set->comd_arg[i][0][0] == '\0')
		return (NULL);
	set->split = ft_split(set->path_env, ':');
	if (set->comd_arg[i][0][0] == '/')
	{
		test_path_cmd = ft_strdup(set->comd_arg[i][0]);
		if (access(test_path_cmd, X_OK) == 0)
			return (test_path_cmd);
	}
	else
		return (ft_path_cmd_2(set, i));
	return (NULL);
}
