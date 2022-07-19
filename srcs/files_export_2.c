/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_export_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:27:10 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 10:27:40 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export2(t_setting *set, int j, char *str)
{
	while (set->var_envp[++j])
	{
		if (ft_strncmp(set->var_envp[j], "PWD", 3) == 0
			&& set->var_envp[j][3] == '=')
		{
			free(set->var_envp[j]);
			set->var_envp[j] = ft_strjoin("", "PWD=");
			str = set->var_envp[j];
			set->var_envp[j] = ft_strjoin(str, set->prompt);
			free(str);
		}
	}
}
