/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:13:11 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/01 16:56:17 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelt;

	if (!f || !lst)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newelt = ft_lstnew(f(lst->content));
		if (newelt == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newelt);
		lst = lst->next;
	}
	return (newlst);
}

/*
Prototype
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

Valeur de retour
La nouvelle liste.
NULL si l’allocation échoue 

Fonctions externes autorisees
malloc, free
          
Paramètres
lst: L’adresse du pointeur vers un élément. 
f: L’adresse de la fonction à appliquer. 
del: L’adresse de la fonction permettant de supprimer le 
contenu d’un élément.
 
Description
Itère sur la liste ’lst’ et applique la fonction ’f ’au contenu de chaque 
élément. Crée une nouvelle liste résultant des applications successives 
de ’f’. La fonction ’del’ est là pour détruire le contenu d’un élément 
si nécessaire.
test 8123
*/
