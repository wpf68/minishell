/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_error__name_minishell.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:12:47 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:13:12 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(char *str, int nb)
{
	if (nb == 1)
		perror(str);
	exit(0);
}

int	ft_name_minishell(t_setting *set)
{
	char	prompt[SIZE_PROMPT];
	int		j;

	if (!getcwd(prompt, sizeof(prompt)))
		ft_error("error getcwd", 1);
	j = ft_strlen(prompt);
	set->var = ft_strnstr(prompt, set->path_begin, j);
	if (!set->var)
	{
		j = -1;
		while (prompt[++j])
			set->path_end[j] = prompt[j];
		set->path_end[j] = '\0';
		return (0);
	}
	set->path_end[0] = '~';
	j = 1;
	set->var = set->var + ft_strlen(set->path_begin) - 1;
	while ((char) *set->var++)
		set->path_end[j++] = (char) *set->var;
	set->path_end[j] = '\0';
	return (0);
}
