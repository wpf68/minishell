/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:30:28 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/01 16:09:43 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pt;

	pt = (t_list *)malloc(sizeof(t_list));
	if (pt == NULL)
		return (NULL);
	pt->content = content;
	pt->next = NULL;
	return (pt);
}

/*
Prototype 
t_list *ft_lstnew(void *content);

Paramètres 
content: Le contenu du nouvel élément.

Valeur de retour 
Le nouvel élément

Fonctions externes autorisées
malloc

Description 
Alloue (avec malloc(3)) et renvoie un nouvel
élément. La variable membre ’content’ est
initialisée à l’aide de la valeur du paramètre
’content’. La variable ’next’ est initialisée à
NULL.
*/
