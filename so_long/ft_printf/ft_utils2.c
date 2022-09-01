/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:20:23 by meudier           #+#    #+#             */
/*   Updated: 2022/05/30 08:40:40 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadrs(void *adrs)
{
	char			*hexa;
	unsigned long	adr;
	int				len;
	int				rtr;

	adr = (unsigned long)adrs;
	hexa = "0123456789abcdef";
	len = 1;
	if (adr / 16 == 0 && adr % 16 == 0)
	{
		rtr = write (1, "(nil)", 5);
		return (5);
	}
	if (adr / 16)
		len += ft_putadrs((void *)(adr / 16));
	else
	{
		rtr = write (1, "0x", 2);
		len += 2;
	}
	rtr = write (1, &hexa[adr % 16], 1);
	(void)rtr;
	return (len);
}

int	ft_puthexa(unsigned int nb)
{
	char	*hexa;
	int		len;

	hexa = "0123456789abcdef";
	len = 1;
	if (nb / 16)
		len += ft_puthexa(nb / 16);
	if (write (1, &hexa[nb % 16], 1) <= 0)
		return (0);
	return (len);
}

int	ft_puthexa_maj(unsigned int nb)
{
	char	*hexa;
	int		len;

	hexa = "0123456789ABCDEF";
	len = 1;
	if (nb / 16)
		len += ft_puthexa_maj(nb / 16);
	if (write (1, &hexa[nb % 16], 1) <= 0)
		return (0);
	return (len);
}
