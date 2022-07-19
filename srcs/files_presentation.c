/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_presentation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:28:46 by pwolff            #+#    #+#             */
/*   Updated: 2022/07/04 11:29:13 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_progress_bar(char c, int k)
{
	int	i;
	int	j;

	i = 0;
	while (++i < 57)
	{
		write(1, &c, 1);
		j = i * (k / 50);
		while (j < k)
			j++;
	}
	printf("\n\033[0;36m\n\n");
	printf("\033[1;36m");
}

static void	ft_header(void)
{
	printf("\n	");
	printf("\x1B[1;32m        _       _     \x1B[33m_          _ _");
	printf("\n	");
	printf("\x1B[32m  /\\/\\ (_)_ __ (_)\x1B[33m___| |__   ___| | |");
	printf("\n	");
	printf("\x1B[32m /    \\| | '_ \\| \x1B[33m/ __| '_ \\ / _ \\ | |");
	printf("\n	");
	printf("\x1B[32m/ /\\/\\ \\ | | | | \x1B[33m\\__ \\ | | |  __/ | |");
	printf("\n	");
	printf("\x1B[32m\\/    \\/_|_| |_|_\x1B[33m|___/_| |_|\\___|_|_|");
	printf("\n	");
	printf("\n\033[36m\n");
	printf("\033[7;35m\n");
	ft_progress_bar(' ', 50000000);
}

void	ft_presentation(void)
{
	int		fd;
	char	*str;
	int		j;

	system("clear");
	ft_header();
	fd = open("srcs/.init.rc", O_RDONLY);
	if (fd == -1)
		ft_error("Eror fd\n", 1);
	while (1)
	{
		str = get_next_line(fd);
		j = 0;
		while (j < 10000000)
			j++;
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd);
	ft_progress_bar('=', 5000000);
	printf("\n\033[0;37m");
}
