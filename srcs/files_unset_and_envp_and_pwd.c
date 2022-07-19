/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_unset_and_envp_and_pwd.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:29 by pwolff            #+#    #+#             */
/*   Updated: 2022/06/27 17:16:25 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_setting *set, int i)
{
	int	j;
	int	len;

	g_signale.status = 0;
	if (set->comd_arg[i][1] == NULL)
		return ;
	len = ft_strlen(set->comd_arg[i][1]);
	j = -1;
	while (set->var_envp[++j])
		if (ft_strncmp(set->var_envp[j], set->comd_arg[i][1], len) == 0
				&& set->var_envp[j][len] == '=')
			set->var_envp[j][0] = ' ';
	if (ft_strncmp(set->comd_arg[i][1], "PATH", len) == 0)
		set->path_env = NULL;
}

static void	ft_envp_export_empty_2(t_setting *set, int i, int j)
{
	i = -1;
	while (set->var_envp[++i])
	{
		j = 0;
		while (set->sort_env[j] != i)
			j++;
		if (set->var_envp[j][0] != ' '
				&& ft_strncmp(set->var_envp[j], "?=", 2) != 0)
			printf("%s\n", set->var_envp[j]);
	}
	g_signale.status = 0;
}

void	ft_envp_export_empty(t_setting *set)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 1000)
		set->sort_env[i] = 0;
	i = -1;
	while (set->var_envp[++i])
	{
		j = -1;
		while (set->var_envp[++j])
			if (ft_strncmp(set->var_envp[i], \
					set->var_envp[j], 100) > 0)
				set->sort_env[i] += 1;
	}
	ft_envp_export_empty_2(set, i, j);
}

void	ft_envp(t_setting *set)
{
	int	i;

	i = -1;
	while (set->var_envp[++i])
		if (set->var_envp[i][0] != ' '
				&& ft_strncmp(set->var_envp[i], "?=", 2) != 0)
			printf("%s\n", set->var_envp[i]);
	g_signale.status = 0;
	exit(0);
}

void	ft_pwd(t_setting *set)
{
	if (!getcwd(set->prompt, sizeof(set->prompt)))
		ft_error("error getcwd", 1);
	printf("%s\n", set->prompt);
	g_signale.status = 0;
	exit(0);
}
