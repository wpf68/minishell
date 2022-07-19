/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:48:10 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 11:48:41 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
 
isalnum()
vérifie si l'on a un caractère alphanumérique. C'est équivalent à 
(isalpha(c) || isdigit(c)).

Les valeurs renvoyées sont non nulles si le caractère c entre dans la 
catégorie testée, 
et zéro sinon  

*/
