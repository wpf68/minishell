/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_child_parent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:04:38 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:05:53 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_child_double_arrow(t_setting *set, int j)
{
	int		fd;
	char	*str;

	ft_double_arrow(set, j);
	if (set->cmd_shell[j + 1])
		dup2(set->pdes[1], STDOUT_FILENO);
	fd = open(".heredoc", O_RDONLY);
	if (fd == -1)
		ft_error("Error fd\n", 1);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd);
	exit(0);
}

void	ft_child(t_setting *set, int j)
{
	dup2(1, STDOUT_FILENO);
	if (set->redirect >= 3)
	{
		if (set->redirect == 3)
			dup2(set->fd, STDOUT_FILENO);
		else if (set->redirect == 4)
			dup2(set->fd, STDOUT_FILENO);
	}
	else if (set->cmd_shell[j + 1] && set->redirect != 2)
		dup2(set->pdes[1], STDOUT_FILENO);
	if (set->redirect == 1)
		dup2(set->fd, STDIN_FILENO);
	else
		dup2(set->in, STDIN_FILENO);
	if (set->redirect == 2)
		ft_child_double_arrow(set, j);
	close(set->pdes[0]);
	if (set->redirect != 2)
		ft_exec_cmd(set, j);
	ft_error("error pipe\n", 1);
}

void	ft_parent(t_setting *set, int j)
{
	int	i;
	int	len;

	waitpid(0, &i, 0);
	g_signale.status = WEXITSTATUS(i);
	len = ft_strlen(set->comd_arg[j][0]);
	if (len == 5 && ft_strncmp(set->comd_arg[j][0], "unset", 5) == 0)
		ft_unset(set, j);
	else if (len == 2 && ft_strncmp(set->comd_arg[j][0], "cd", 2) == 0)
		ft_cd(set, j);
	else if (len == 6 && ft_strncmp(set->comd_arg[j][0], "export", 6) == 0)
		ft_export(set, j);
	else if (len == 4 && ft_strncmp(set->comd_arg[j][0], "exit", 4) == 0)
		ft_exit(set, j);
	else if (len == 5 && ft_strncmp(set->comd_arg[j][0], "color", 5) == 0)
		set->color++;
	close(set->pdes[1]);
	set->in = set->pdes[0];
	if (set->redirect == 3 || set->redirect == 4)
		set->in = 0;
}
