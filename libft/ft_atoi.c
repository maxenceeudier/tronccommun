/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:56:49 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 13:26:43 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((int)(str[i]) == 32
		|| ((int)(str[i]) >= 9 && (int)(str[i]) <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
/*
#include <stdio.h>

int main()
{
printf("%d", ft_atoi("  \t \n\r \v \f -234arefdsb"));
return (0);
}*/
