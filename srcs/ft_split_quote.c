/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:17:00 by pwolff            #+#    #+#             */
/*   Updated: 2022/06/29 07:57:51 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_part(char const *s, char c)
{
	int	part;
	int	test;

	part = 0;
	test = 0;
	while (*s)
	{
		if (*s != c && test == 0)
		{
			part++;
			test = 1;
		}
		else if (*s == c)
			test = 0;
		s++;
	}
	return (part);
}

static char	*ft_tab(char const *str, int start, int finish)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}

static void	ft_split_q_3(t_setting *set, char const *s, size_t i)
{
	if (set->dq == 0 && set->q == 0)
	{
		set->split[set->j++] = ft_tab(s, set->index, i);
		set->index = -1;
		set->dq = 0;
		set->q = 0;
	}
}

static void	ft_split_q_2(t_setting *set, char const *s, char c, size_t i)
{
	while (i <= ft_strlen(s))
	{
		if (s[i] == '"' && set->dq == 0 && set->q == 0)
			set->dq = 1;
		else if (s[i] == '"' && set->dq == 1)
			set->dq = 0;
		if (s[i] == '\'' && set->q == 0 && set->dq == 0)
			set->q = 1;
		else if (s[i] == '\'' && set->q == 1)
			set->q = 0;
		if (s[i] != c && set->index < 0)
			set->index = i;
		else if ((s[i] == c
				|| i == ft_strlen(s)) && set->index >= 0)
			ft_split_q_3(set, s, i);
		i++;
	}
}

char	**ft_split_quote(t_setting *set, char const *s, char c)
{
	size_t	i;

	if (!s)
		return (NULL);
	set->split = malloc((ft_part(s, c) + 1) * sizeof(char *));
	if (!s || !set->split)
		return (NULL);
	i = 0;
	set->j = 0;
	set->dq = 0;
	set->q = 0;
	set->index = -1;
	ft_split_q_2(set, s, c, i);
	set->split[set->j] = 0;
	return (set->split);
}
