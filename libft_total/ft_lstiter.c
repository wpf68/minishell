/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:00:44 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/01 14:11:21 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
Prototype
void ft_lstiter(t_list *lst, void (*f)(void *));

Paramettres
lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.

Aucune
Aucune

Description
Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu 
chaque élément.
*/
