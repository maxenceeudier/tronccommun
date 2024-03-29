/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:22:52 by meudier           #+#    #+#             */
/*   Updated: 2022/06/06 12:02:03 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char c, va_list *ap)
{
	int	len;

	if (c == 's')
		len = ft_putstr(va_arg(*ap, char *));
	else if (c == 'i' || c == 'd')
		len = ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (c == 'c')
		len = ft_putchar(va_arg(*ap, int));
	else if (c == 'p')
		len = ft_putadrs(va_arg(*ap, void *));
	else if (c == 'u')
		len = ft_putnbr_u(va_arg(*ap, unsigned int));
	else if (c == 'x')
		len = ft_puthexa(va_arg(*ap, unsigned int));
	else if (c == 'X')
		len = ft_puthexa_maj(va_arg(*ap, unsigned int));
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_print(str[i], &ap);
		}
		else
		{
			write (1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

/*
#include <stdio.h>
#include <limits.h>

int main()
{
char    test[] = "mec";
int     d = 2;
int     u = 6;
int     nb = 4536;
char    c = 'a';
unsigned int big = 3000000000;


ft_printf("%s", 45);
return (0);
}*/
