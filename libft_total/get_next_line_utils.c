/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:07:57 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/17 13:10:22 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_strchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 1;
	while (s[len] != c && s[len] != '\0')
		len++;
	if (s[len] == c)
		return (len);
	return (0);
}

static size_t	get_strlen(const char *str)
{
	unsigned long int	i;

	i = 0;
	while (str != NULL && str[i])
		i++;
	return (i);
}

static void	*get_memcpy(void *dest, const void *src, unsigned long int n)
{
	unsigned long int	i;
	char				*first;
	char				*secound;

	if (dest == NULL && src == NULL)
		return (dest);
	first = (char *)dest;
	secound = (char *)src;
	i = 0;
	while (i < n)
	{
		first[i] = secound[i];
		i++;
	}
	return (dest);
}

static void	get_bzero(void *s, unsigned long int n)
{
	unsigned long int	i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*get_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	size = get_strlen((char *)s1) + get_strlen((char *)s2) + 1;
	tab = NULL;
	tab = (char *)(malloc(sizeof(char) * size));
	if (tab == NULL)
		return (NULL);
	get_bzero(tab, size);
	size = get_strlen((char *)s1);
	get_memcpy(tab, (char *)s1, size);
	get_memcpy(&tab[size], (char *)s2, get_strlen((char *)s2));
	return (tab);
}
