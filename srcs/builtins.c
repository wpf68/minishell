/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:56:02 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/28 08:15:21 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_test_builtins(t_setting *set, int i)
{
	int	len;

	len = ft_strlen(set->comd_arg[i][0]);
	if (len == 5 && ft_strncmp(set->comd_arg[i][0], "color", 5) == 0)
		return (0);
	if (len == 4 && ft_strncmp(set->comd_arg[i][0], "exit", 4) == 0)
		return (0);
	if (len == 2 && ft_strncmp(set->comd_arg[i][0], "cd", 2) == 0)
		return (0);
	if (len == 3 && ft_strncmp(set->comd_arg[i][0], "env", 3) == 0)
		return (0);
	if (len == 5 && ft_strncmp(set->comd_arg[i][0], "unset", 5) == 0)
		return (0);
	if (len == 6 && ft_strncmp(set->comd_arg[i][0], "export", 6) == 0)
		return (0);
	if (len == 3 && ft_strncmp(set->comd_arg[i][0], "pwd", 3) == 0)
		return (0);
	if (len == 4 && ft_strncmp(set->comd_arg[i][0], "echo", 4) == 0)
		return (0);
	if (len == 2 && ft_strncmp(set->comd_arg[i][0], "<<", 2) == 0)
		return (0);
	return (1);
}

int	ft_run_builtins(t_setting *set, int i)
{
	int	len;

	len = ft_strlen(set->comd_arg[i][0]);
	if (len == 2 && ft_strncmp(set->comd_arg[i][0], "cd", 2) == 0)
		return (1);
	else if (len == 5 && ft_strncmp(set->comd_arg[i][0], "color", 5) == 0)
		return (1);
	else if (len == 3 && ft_strncmp(set->comd_arg[i][0], "env", 3) == 0)
		ft_envp(set);
	else if (len == 5 && ft_strncmp(set->comd_arg[i][0], "unset", 5) == 0)
		return (1);
	else if (len == 6 && ft_strncmp(set->comd_arg[i][0], "export", 6) == 0)
		return (1);
	else if (len == 3 && ft_strncmp(set->comd_arg[i][0], "pwd", 3) == 0)
		ft_pwd(set);
	else if (len == 4 && ft_strncmp(set->comd_arg[i][0], "echo", 4) == 0)
		ft_echo(set, i);
	else if (len == 4 && ft_strncmp(set->comd_arg[i][0], "exit", 4) == 0)
		return (1);
	return (0);
}
