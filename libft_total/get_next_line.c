/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:07:03 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/17 13:09:54 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_load(t_list_get *g, char *tab)
{
	while (get_strchr(g->tabs, '\n') == 0)
	{
		g->len = read(g->fd, tab, 1);
		if (g->len < 0)
			return ;
		tab[g->len] = '\0';
		if (g->len == 0)
			return ;
		g->temp = g->tabs;
		g->tabs = get_strjoin(g->temp, tab);
		free(g->temp);
		if (tab[0] == '\n')
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	tab[2];
	t_list_get	main;

	tab[0] = '\0';
	if (fd < 0)
		return (NULL);
	main.fd = fd;
	main.tabs = (char *)malloc(sizeof(char) * 2);
	if (main.tabs == NULL)
		return (NULL);
	main.tabs[0] = '\0';
	get_load(&main, tab);
	if ((main.tabs[0] == '\0' && main.len == 0) || main.len == -1)
	{
		free(main.tabs);
		return (NULL);
	}
	return (main.tabs);
}

/* taille des structures !!!
 * test des size de 1 à 10 000 000 ok
 * fd pointer sur fichiers standart ou entrées standart !!!
*/
