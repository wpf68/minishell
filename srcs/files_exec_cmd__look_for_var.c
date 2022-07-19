/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_exec_cmd__look_for_var.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:07:32 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 11:00:05 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_cmd(t_setting *set, int j)
{
	char	*args[2550];
	int		i;

	if (ft_run_builtins(set, j))
		exit (0);
	args[0] = ft_path_cmd(set, j);
	if (args[0] == NULL)
		exit(0);
	i = 0;
	while (set->comd_arg[j][++i])
		args[i] = set->comd_arg[j][i];
	args[i] = NULL;
	close(set->fd);
	if (execve(args[0], args, set->var_envp) == -1)
		g_signale.status = errno;
	exit(0);
}

static char	*ft_look_for_var_2(t_setting *set, char *str, char *var)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (set->var_envp[++i])
	{
		j = ft_strlen(str);
		if (ft_strncmp(set->var_envp[i], str, j) == 0
			&& set->var_envp[i][j] == '=')
		{
			var = malloc(sizeof(var) * 4096);
			if (var == NULL)
				ft_error("Error malloc ft_interpreter", 1);
			k = -1;
			while (set->var_envp[i][++j])
				var[++k] = set->var_envp[i][j];
			var[++k] = '\0';
			break ;
		}
	}
	return (var);
}

char	*ft_look_for_var(t_setting *set, char *str)
{
	char	*var;

	var = NULL;
	var = ft_look_for_var_2(set, str, var);
	if (var == NULL)
	{
		var = malloc(sizeof(var) * 1);
		if (var == NULL)
			ft_error("Error malloc ft_interpreter", 1);
		var[0] = '\0';
	}	
	return (var);
}
