/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:21:57 by meudier           #+#    #+#             */
/*   Updated: 2022/05/03 19:29:08 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int     ft_printf(const char *, ...);
int    ft_putstr(char *str);
int    ft_putnbr_fd(int n, int fd);
int    ft_putnbr_u(unsigned int n);
int    ft_putchar(int c);
int    ft_putadrs(void *adrs);
int    ft_puthexa(unsigned long long nb);
int    ft_puthexa_maj(unsigned long long nb);

#endif