/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:50:57 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 14:16:10 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
 
isascii()
vérifie si c est un unsigned char sur 7 bits, entrant dans le jeu de 
caractères ASCII.

Les valeurs renvoyées sont non nulles si le caractère c entre dans la 
catégorie testée, 
et zéro sinon  

*/
