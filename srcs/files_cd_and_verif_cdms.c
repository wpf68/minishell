/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_cd_and_verif_cdms.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:46:18 by pwolff            #+#    #+#             */
/*   Updated: 2022/06/27 16:48:06 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_search_home(t_setting *set)
{
	int	j;
	int	i;

	set->temp[0] = '\0';
	j = -1;
	set->k = 0;
	while (set->var_envp[set->k])
		set->k += 1;
	while (set->var_envp[++j])
	{
		if (ft_strncmp(set->var_envp[j], "HOME=", 5) == 0)
		{
			i = -1;
			while (set->var_envp[j][++i + 5])
				set->temp[i] = set->var_envp[j][i + 5];
			set->temp[i] = '\0';
			break ;
		}
	}
	if (set->k == j)
		printf("HOME no set\n");
}

void	ft_cd(t_setting *set, int i)
{
	if (!set->comd_arg[i][1] || (set->comd_arg[i][1][0] == '~'
			&& set->comd_arg[i][1][1] == '\0'))
	{
		ft_search_home(set);
		if (chdir(set->temp) && set->temp[0])
			perror (set->temp);
	}
	else
	{
		if (chdir(set->comd_arg[i][1]))
			perror (set->comd_arg[i][1]);
	}
	if (!getcwd(set->prompt, sizeof(set->prompt)))
		ft_error("error getcwd", 1);
	ft_export(set, -1);
	g_signale.status = 0;
}

void	ft_verif_cmds(t_setting *set)
{
	int		i;
	int		j;

	i = -1;
	while (set->cmd_shell[++i])
	{
		printf("%d = --%s-- \n", i, set->cmd_shell[i]);
		j = -1;
		while (set->comd_arg[i][++j])
			printf(" arg %d = --%s-- \n", j, set->comd_arg[i][j]);
	}
	printf("total cmd shell : %d\n\n", set->nb_command);
}
