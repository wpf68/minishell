/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:52:14 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 11:52:30 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
 
isdigit()
vérifie si l'on a un chiffre (0 à 9).

Les valeurs renvoyées sont non nulles si le caractère c entre dans la 
catégorie testée, 
et zéro sinon  

*/
