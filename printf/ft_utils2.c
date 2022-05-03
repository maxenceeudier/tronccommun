/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:20:23 by meudier           #+#    #+#             */
/*   Updated: 2022/05/03 19:36:15 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putadrs(void *adrs)
{
    char    *hexa;
    unsigned long adr;
    int     len;
    
    adr = (unsigned long)adrs;
    hexa = "0123456789abcdef";
    len = 1;
    if (adr / 16 == 0 && adr % 16 == 0)
    {
        write (1, "(nil)", 5);
        return (5);
    }
    if (adr / 16)
        len += ft_putadrs((void *)(adr / 16));
    else
    {
        write (1, "0x", 2);
        len += 2;
    } 
    write (1, &hexa[adr % 16], 1);
    return (len);
}

int    ft_puthexa(unsigned long long nb)
{
    char    *hexa;
    int     len;
    
    hexa = "0123456789abcdef";
    len = 1;
    if (nb / 16)
        len += ft_puthexa(nb / 16);
    write (1, &hexa[nb % 16], 1);
    return (len);
}

int    ft_puthexa_maj(unsigned long long nb)
{
    char    *hexa;
    int     len;
    
    hexa = "0123456789ABCDEF";
    len = 1;
    if (nb / 16)
        len += ft_puthexa_maj(nb / 16);
    write (1, &hexa[nb % 16], 1);
    return (len);
}