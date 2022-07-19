/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:00:33 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/01 13:21:05 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}
/*
Prototype
void ft_lstdelone(t_list *lst, void (*del)(void *));

Valeur de retour
Aucune 

Fonctions externes autorisees
free

Paramètres
lst: L’élément à free
del: L’adresse de la fonction permettant de supprimer le 
contenu de l’élément.
 
Description
Libère la mémoire de l’élément passé en argument en utilisant la fonction ’del’ 
puis avec free(3). La mémoire de ’next’ ne doit pas être free.
*/
