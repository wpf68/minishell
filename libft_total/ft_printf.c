/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:01:29 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/07 14:23:36 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_process(char c, char d, int *i)
{
	if (c != '%')
	{	
		ft_putchar_fd(c, 1);
		*i = *i + 1;
		return (1);
	}
	if (c == '%' && d == '%')
	{	
		ft_putchar_fd(c, 1);
		*i = *i + 1;
		return (2);
	}
	if (c == '%' && (d != 'c' && d != 's' && d != 'i' && d != 'd'
			&& d != 'u' && d != 'x' && d != 'X'
			&& d != 'p' && d != '\0'))
	{	
		ft_putchar_fd(c, 1);
		*i = *i + 1;
		return (-1);
	}
	if (c == '%' && d == '\0')
		return (-1);
	return (0);
}

static void	ft_conversion(char c, va_list ap, int *i)
{
	if (c == 'c')
		ft_printf_c(ap, i);
	else if (c == 's')
		ft_printf_s(ap, i);
	else if (c == 'i' || c == 'd')
		ft_printf_d_i(ap, i);
	else if (c == 'u')
		ft_printf_u(ap, i);
	else if (c == 'x' || c == 'X')
		ft_printf_x(ap, i, c);
	else if (c == 'p')
		ft_printf_p(ap, i);
}

int	ft_printf(const char *tab, ...)
{
	va_list	ap;
	int		test;
	int		size;
	int		i;

	va_start(ap, tab);
	size = 0;
	i = 0;
	while (tab[size])
	{
		test = ft_process(tab[size], tab[size + 1], &i);
		if (test == -1)
			return (-1);
		if (test == 0)
		{
			size++;
			ft_conversion(tab[size], ap, &i);
			size++;
		}
		size = size + test;
	}
	va_end(ap);
	return (i);
}

/*
https://en.wikipedia.org/wiki/Stdarg.h

void
foo(char *fmt, ...)
{
    va_list ap;
    int d;
    char c, *s;

   va_start(ap, fmt);
    while (*fmt)
        switch (*fmt++) {
        case 's':               string 
            s = va_arg(ap, char *);
            printf("string %s\n", s);
            break;
        case 'd':               int 
            d = va_arg(ap, int);
            printf("int %d\n", d);
            break;
        case 'c':               char 
            * need a cast here since va_arg only
               takes fully promoted types *
            c = (char) va_arg(ap, int);
            printf("char %c\n", c);
            break;
        }
    va_end(ap);
}
*/
/*
Vous devez implémenter les conversions suivantes :
• %c Affiche un seul caractère.
• %s Affiche une chaîne de caractères (telle que définie par la convention C).
• %p L’argument de pointeur void * doit être affiché en hexadécimal.
• %d Affiche un nombre décimal (base 10).
• %i Affiche un entier en base 10.
• %u Affiche un nombre décimal non signé (base 10).
• %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
• %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
• %% Affiche un signe pourcentage.

Liste de bonus :
• Gérez toute combinaison des drapeaux suivants : ’-0.’ ainsi que la 
largeur minimale du champ avec toutes les conversions.
• Gérez tous les drapeaux suivants : ’# +’ (Oui, l’espace est un drapeau 
valide)
Si vous envisagez de faire des bonus, il vaut mieux réfléchir à leur
implémentation dès le début afin d’éviter une approche "naïve".
*/
