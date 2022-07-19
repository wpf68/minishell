/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:13:27 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/06/29 08:20:18 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_2(t_setting *set, char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
			j++;
		set->var_envp[i] = malloc(sizeof(envp[i]) * (j + 1));
		if (set->var_envp[i] == NULL)
			ft_error("error malloc envp[i]", 1);
		j = -1;
		while (envp[i][++j])
			set->var_envp[i][j] = envp[i][j];
		set->var_envp[i][j] = '\0';
		i++;
	}
	i--;
	while (++i < 1000)
		set->var_envp[i] = NULL;
}

static void	ft_init_3(t_setting *set, int i, int j)
{
	set->path_begin[j] = '\0';
	set->path_cd[i] = '/';
	set->path_cd[i + 1] = '\0';
	set->path_env = getenv("PATH");
	g_signale.status = 0;
	ft_name_minishell(set);
	set->on_off = 1;
	set->path_prompt = NULL;
	ft_search_prompt(set);
	set->command = NULL;
	set->cmd_shell = NULL;
	set->nb_command = 0;
	set->redirect = 0;
	set->name_redirect = NULL;
	g_signale.child = 0;
	set->double_arrow = 0;
	set->debug = 0;
	set->color = 0;
}

static void	ft_init_4(t_setting *set, int i, int j, char **envp)
{
	ft_init_3(set, i, j);
	set->var_envp = malloc(sizeof(envp) * (1000));
	if (set->var_envp == NULL)
		ft_error("error malloc envp", 1);
	ft_init_2(set, envp);
}

void	ft_init(t_setting *set, char **envp)
{
	int		i;
	int		j;
	char	prompt[SIZE_PROMPT];

	if (!getcwd(prompt, sizeof(prompt)))
		ft_error("error getcwd init", 1);
	i = -1;
	j = 0;
	while (prompt[++i] != '/' || j < 1)
	{
		if (prompt[i] == '/')
			j++;
		set->path_cd[i] = prompt[i];
	}
	set->path_cd[i] = '/';
	j = 0;
	while (prompt[++i] != '/' && prompt[i] != '\0')
	{
		set->path_begin[j++] = prompt[i];
		set->path_cd[i] = prompt[i];
	}
	ft_init_4(set, i, j, envp);
}
