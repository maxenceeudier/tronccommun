/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:45:58 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 17:47:42 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int	ft_get_size(int *n)
{
	int	count;
	int	nb;

	if (*n < 0)
		*n *= -1;
	count = 1;
	nb = *n;
	while (nb / 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static void	rev(char **tab)
{
	int		i;
	int		size;
	char	temp;

	i = 0;
	while ((*tab)[i])
		i++;
	size = i;
	i = 0;
	while (i < size / 2)
	{
		temp = (*tab)[i];
		(*tab)[i] = (*tab)[size - 1 - i];
		(*tab)[size - 1 - i] = temp;
		i++;
	}
}

static void	init_value(int *i, int *sign)
{
	*i = 0;
	*sign = 0;
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		sign;

	init_value(&i, &sign);
	if (n < 0)
		sign = 1;
	if (n == -2147483648)
	{
		tab = "-2147483648";
		return (tab);
	}
	tab = (char *)malloc(ft_get_size(&n) + sign + 1);
	if (!tab)
		return (NULL);
	while (n)
	{
		tab[i++] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		tab[i++] = '-';
	tab[i] = 0;
	rev(&tab);
	return (tab);
}
/*
#include <stdio.h>

int main()
{
printf("%s", ft_itoa(-147364));
return (0);
}*/
