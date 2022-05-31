/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:19:20 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 08:41:30 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		while (*str)
		{
			if (write (1, str++, 1) <= 0)
				return (0);
			len++;
		}
	}
	else
	{
		if (write (1, "(null)", 6) <= 0)
			return (0);
		return (6);
	}
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	temp;
	int		len;
	int		rtr;

	if (n == -2147483648)
	{
		rtr = write (fd, "-2147483648", 11);
		return (11);
	}
	else
	{
		len = 1;
		if (n < 0)
		{
			n *= -1;
			len++;
			rtr = write (fd, "-", 1);
		}
		if (n / 10)
			len += ft_putnbr_fd(n / 10, fd);
		temp = n % 10 + '0';
		rtr = write (fd, &temp, 1);
		return (len);
	}
	(void)rtr;
}

int	ft_putnbr_u(unsigned int n)
{
	char	temp;
	int		len;

	len = 1;
	if (n / 10)
		len += ft_putnbr_u(n / 10);
	temp = n % 10 + '0';
	if (write (1, &temp, 1) <= 0)
		return (0);
	return (len);
}

int	ft_putchar(int c)
{
	char	temp;

	temp = (char)c;
	if (write (1, &temp, 1) <= 0)
		return (0);
	return (1);
}
