/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:15:46 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/01 16:59:59 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next && size++)
		lst = lst->next;
	return (size);
}

/*
Prototype
int ft_lstsize(t_list *lst);

Parametres
lst: Le début de la liste. 

Valeur de retour
Taille de la liste

Fonctions externes
Aucune

Description
Compte le nombre d’éléments de la liste.
*/
