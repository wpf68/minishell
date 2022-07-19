/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_echo_and_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:48:39 by pwolff            #+#    #+#             */
/*   Updated: 2022/07/04 11:26:36 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_setting *set, int i)
{
	int	j;
	int	len;
	int	k;

	j = 0;
	len = ft_strlen(set->comd_arg[i][1]);
	if (len == 2 && ft_strncmp(set->comd_arg[i][1], "-n", 2) == 0)
		j++;
	while (set->comd_arg[i][++j])
	{
		printf("%s", set->comd_arg[i][j]);
		k = 0;
		while (set->comd_arg[i][j][k])
			k++;
		if (set->comd_arg[i][j][k - 1] != ' '
				&& set->comd_arg[i][j + 1])
			printf(" ");
	}
	if (len == 2 && ft_strncmp(set->comd_arg[i][1], "-n", 2) == 0)
		exit(0);
	printf("\n");
	exit(0);
}

static void	ft_exit_quit(t_setting *set, int num, int i, int test)
{
	printf("\033[1m");
	printf("\033[31m");
	printf("\nexit (%d)", num);
	printf("\033[32m");
	printf(" @minishell\n\n");
	printf("\033[0m");
	free(set->path_prompt);
	ft_free_env(set);
	if (i == -1)
		exit(0);
	else if (i == 1 || (i == 2 && test))
		exit(num);
	else if (test == 0)
		printf("exit: num arg required\n");
	if (i == 2)
		exit(num);
}

void	ft_exit(t_setting *set, int j)
{
	int	i;
	int	test;
	int	k;
	int	num;

	i = 1;
	test = 1;
	if (j == -1)
		ft_exit_quit(set, 0, -1, 0);
	while (set->comd_arg[j][i])
		i++;
	if (i >= 2)
	{
		k = -1;
		while (set->comd_arg[j][1][++k])
			if (!ft_isdigit(set->comd_arg[j][1][k]))
				test = 0;
		if (test)
			num = ft_atoi(set->comd_arg[j][1]);
	}
	if (i > 2)
		printf("exit: too many arguments\n");
	else
		ft_exit_quit(set, num, i, test);
}
