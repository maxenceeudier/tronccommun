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

#include "libft.h"
#include <stdio.h>

static int	ft_get_size(int n)
{
	int	count;

	count = 1;
	while (n / 10)
	{
		count++;
		n /= 10;
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

static void	init_value(int *i, int *sign, int *nb, int *len)
{
	*i = 0;
	*len = ft_get_size(*nb);
	if (*nb < 0)
	{
		*sign = 1;
		*nb *= -1;
	}
	else
		*sign = 0;
}

static void	min_tab(char **tab)
{
	char	*temp;
	int		i;

	temp = "-2147483648";
	*tab = (char *)malloc(12);
	i = 0;
	while (i < 12)
	{
		(*tab)[i] = temp[i];
		i++;
	}
}	

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		sign;
	int		len;

	init_value(&i, &sign, &n, &len);
	if (n == -2147483648)
	{
		min_tab(&tab);
		return (tab);
	}
	tab = (char *)malloc(len + sign + 1);
	if (!tab)
		return (NULL);
	while (i < len)
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
printf("%s", ft_itoa(0));
return (0);
}
*/