/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:21:50 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/01 13:57:50 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
/*
Prototype
void ft_lstclear(t_list **lst, void (*del)(void *));

Paramètres
lst: L’adresse du pointeur vers un élément. 
del: L’adresse de la fonction permettant de supprimer le contenu d’un élément.

Valeur de retour 
Aucune

Fonctions externes autorisées
free 

Description
Supprime et libère la mémoire de l’élément passé en paramètre, et de tous 
les éléments qui suivent, à l’aide de ’del’ et de free(3)
Enfin, le pointeur initial doit être mis à NULL
*/
