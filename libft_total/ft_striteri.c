/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:07:07 by pwolff            #+#    #+#             */
/*   Updated: 2022/02/26 13:07:18 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char const *s, void (*f)(unsigned int, char *))
{
	unsigned long int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, (char *)&s[i]);
		i++;
	}
}

/*
Prototype 
void ft_striteri(char *s, void (*f)(unsigned int, char*));

Paramètres 
s: La chaîne de caractères sur laquelle itérer.
f: La fonction à appliquer à chaque caractère.

Valeur de retour 
Aucune

Fonctions externes autorisées
Aucune

Description 
Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères transmise comme argument,
et en passant son index comme premier argument.
Chaque caractère est transmis par adresse à ’f’
afin d’être modifié si nécessaire.
*/
