/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:53:11 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 11:53:54 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
 
isprint()
vérifie s'il s'agit d'un caractère imprimable, y compris l'espace.

Les valeurs renvoyées sont non nulles si le caractère c entre dans 
la catégorie testée, et zéro sinon  

*/
