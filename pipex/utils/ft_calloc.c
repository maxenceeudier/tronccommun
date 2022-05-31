/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:59:47 by meudier           #+#    #+#             */
/*   Updated: 2022/05/31 14:43:46 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*adrs;
	size_t	i;

	adrs = (char *)malloc(size * count);
	if (!adrs)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		adrs[i] = 0;
		i++;
	}
	return ((void *)adrs);
}
