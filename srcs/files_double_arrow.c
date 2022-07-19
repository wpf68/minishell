/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_double_arrow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:02:44 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:03:45 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_double_arrow(t_setting *set, int j)
{
	char	*prompt_arrow;
	int		len_arrow;
	int		len_arg;
	int		fd;
	int		i;

	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	len_arg = ft_strlen(set->comd_arg[j][1]);
	prompt_arrow = "heredoc : ";
	while (1)
	{
		set->command_arrow = NULL;
		set->command_arrow = readline(prompt_arrow);
		len_arrow = ft_strlen(set->command_arrow);
		if (len_arrow == len_arg && ft_strncmp(set->comd_arg[j][1],
			set->command_arrow, len_arrow) == 0)
			break ;
		i = -1;
		while (set->command_arrow[++i])
			write(fd, &set->command_arrow[i], 1);
		write(fd, "\n", 1);
	}
	close(fd);
}
