/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:40:12 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/01 12:59:38 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
Prototype
t_list *ft_lstlast(t_list *lst);

Paramètres
lst: Le début de la liste. 

Valeur de retour 
Dernier élément de la liste

Fonctions externes autorisées 
Aucune 

Description
Renvoie le dernier élément de la liste.
*/
