/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:49:44 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 11:50:21 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
 
isalpha()
vérifie si l'on a un caractère alphabétique. Dans la localisation "C" standard, 
c'est équivalent à (isupper(c) || islower(c)). Dans certaines localisations, 
il peut y avoir des caractères supplémentaires pour lesquels isalpha() 
est vrai, c'est-à-dire pour des lettres qui ne sont ni majuscules ni minuscules.

Les valeurs renvoyées sont non nulles si le caractère c entre dans la catégorie 
testée, et zéro sinon  

*/
