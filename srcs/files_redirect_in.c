/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_redirect_in.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:01:34 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:02:08 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_redirect_in_2(t_setting *set, int j, int i)
{
	set->redirect = 1;
	set->comd_arg[j][i] = NULL;
	if (set->comd_arg[j][i + 1] == NULL)
	{
		set->redirect = 0;
		printf("-minishell: syntax error '|' or 'newline'\n");
		g_signale.status = 2;
		return (1);
	}
	else
	{
		set->fd = open(set->comd_arg[j][i + 1], O_RDONLY);
		while (set->comd_arg[j][++i])
			free(set->comd_arg[j][i]);
		if (set->fd == -1)
		{
			set->redirect = 0;
			printf("%s: No such fl or dir\n", set->name_redirect);
			g_signale.status = 1;
			return (1);
		}
	}
	return (0);
}

int	ft_redirect_in(t_setting *set, int j)
{
	int		i;
	int		len;
	int		len2;
	char	*str;

	i = 0;
	while (set->comd_arg[j][++i])
	{
		len = ft_strlen(set->comd_arg[j][i]);
		len2 = ft_strlen(set->comd_arg[j][i - 1]);
		str = set->comd_arg[j][i - 1];
		if (len2 == 2 && ft_strncmp(str, "<<", 2) == 0)
		{
			set->redirect = 2;
			set->double_arrow = 1;
			return (0);
		}
		if (len == 1 && ft_strncmp(set->comd_arg[j][i], "<", 1) == 0)
			return (ft_redirect_in_2(set, j, i));
	}
	return (0);
}
