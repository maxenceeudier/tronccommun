/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:22:52 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 08:53:54 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char c, va_list *ap)
{
	int	len;

	len = 0;
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
			if (write (1, &str[i], 1) <= 0)
				return (0);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
