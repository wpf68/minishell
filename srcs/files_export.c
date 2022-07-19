/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:19:04 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 10:24:33 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_export3(t_setting *set, int i, int j)
{
	j = -1;
	while (set->comd_arg[i][1][++j] && set->comd_arg[i][1][j] != '=')
		set->name_export[j] = set->comd_arg[i][1][j];
	set->name_export[j] = '\0';
	if (set->comd_arg[i][1][j] == '\0' && (!set->comd_arg[i][2]))
	{
		g_signale.status = 0;
		return (-1);
	}
	if (set->comd_arg[i][1][j] == '\0' && (set->comd_arg[i][2][0] != '='))
	{
		g_signale.status = 0;
		return (-1);
	}
	else if (set->comd_arg[i][1][j] == '\0')
	{
		g_signale.status = 1;
		printf("-bash: export: '%s': invalid  id\n", set->comd_arg[i][2]);
		return (-1);
	}
	set->arg_export[0] = '\0';
	return (j);
}

static void	ft_export4(t_setting *set, int i, int j)
{
	int	k;

	if (set->comd_arg[i][1][j + 1] != '\0')
	{
		k = 0;
		while (set->comd_arg[i][1][++j])
			set->arg_export[k++] = set->comd_arg[i][1][j];
		set->arg_export[k] = '\0';
		if (set->arg_export[0] == '"' || set->arg_export[0] == '\'')
		{
			k = -1;
			while (set->arg_export[++k])
			{
				if (set->arg_export[k + 2] != '\0')
					set->arg_export[k] = set->arg_export[k + 1];
			}
			set->arg_export[k - 2] = '\0';
		}
	}
}

static int	ft_export5(t_setting *set, int j, int len)
{
	char	*str;

	while (set->var_envp[++j])
	{
		if (ft_strncmp(set->var_envp[j], set->name_export, len) == 0
			&& set->var_envp[j][len] == '=')
		{	
			free(set->var_envp[j]);
			set->var_envp[j] = ft_strjoin("", set->name_export);
			str = set->var_envp[j];
			set->var_envp[j] = ft_strjoin(str, "=");
			free(str);
			str = set->var_envp[j];
			set->var_envp[j] = ft_strjoin(str, set->arg_export);
			free(str);
			g_signale.status = 0;
			set->path_env = ft_look_for_var(set, "PATH");
			return (1);
		}
	}
	return (0);
}

static void	ft_export6(t_setting *set, int j)
{
	char	*str;

	j = 0;
	while (set->var_envp[j])
		j++;
	set->var_envp[j] = ft_strjoin("", set->name_export);
	str = set->var_envp[j];
	set->var_envp[j] = ft_strjoin(str, "=");
	free(str);
	str = set->var_envp[j];
	set->var_envp[j] = ft_strjoin(str, set->arg_export);
	free(str);
	set->var_envp[j + 1] = NULL;
	g_signale.status = 0;
	set->path_env = ft_look_for_var(set, "PATH");
}

void	ft_export(t_setting *set, int i)
{
	int		j;
	char	*str;
	int		len;

	j = -1;
	str = NULL;
	if (i == -1)
	{
		ft_export2(set, j, str);
		return ;
	}
	if (set->comd_arg[i][1] == NULL)
	{
		ft_envp_export_empty(set);
		return ;
	}
	j = ft_export3(set, i, j);
	if (j == -1)
		return ;
	ft_export4(set, i, j);
	j = -1;
	len = ft_strlen(set->name_export);
	if (ft_export5(set, j, len))
		return ;
	ft_export6(set, j);
}
