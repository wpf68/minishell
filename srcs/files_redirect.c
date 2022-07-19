/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:00:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:01:00 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_redirect_open_append(t_setting *set, int j, int i)
{
	char	*str;

	str = set->comd_arg[j][i + 1];
	set->fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0644);
}

static int	ft_redirect_2(t_setting *set, int j, int i)
{
	set->redirect = 4;
	set->comd_arg[j][i] = NULL;
	if (set->comd_arg[j][i + 1] == NULL)
	{
		set->redirect = 0;
		printf("-minishell: syntax error token '|' or 'newline'\n");
		g_signale.status = 2;
		return (1);
	}
	else
	{
		ft_redirect_open_append(set, j, i);
		while (set->comd_arg[j][++i])
			free(set->comd_arg[j][i]);
		if (set->fd == -1)
			ft_error("error create file\n", 1);
		return (0);
	}
}

static void	ft_redirect_open_trunc(t_setting *set, int j, int i)
{
	char	*str;

	str = set->comd_arg[j][i + 1];
	set->fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

static int	ft_redirect_3(t_setting *set, int j, int i)
{
	set->redirect = 3;
	set->comd_arg[j][i] = NULL;
	if (set->comd_arg[j][i + 1] == NULL)
	{
		set->redirect = 0;
		printf("-minishell: syntax error token '|' or 'newline'\n");
		g_signale.status = 2;
		return (1);
	}
	else
	{
		ft_redirect_open_trunc(set, j, i);
		while (set->comd_arg[j][++i])
			free(set->comd_arg[j][i]);
		if (set->fd == -1)
			ft_error("error create file\n", 1);
		return (0);
	}
}

int	ft_redirect(t_setting *set, int j)
{
	int	i;
	int	len;

	i = -1;
	while (set->comd_arg[j][++i])
	{
		len = ft_strlen(set->comd_arg[j][i]);
		if (len == 2 && ft_strncmp(set->comd_arg[j][i], ">>", 2) == 0)
			return (ft_redirect_2(set, j, i));
		if (len == 1 && ft_strncmp(set->comd_arg[j][i], ">", 1) == 0)
			return (ft_redirect_3(set, j, i));
	}
	return (0);
}
