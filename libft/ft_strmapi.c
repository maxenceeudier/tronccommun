/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:48:13 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 17:49:08 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		i;

	i = 0;
	map = (char *)malloc(ft_strlen(s) + 1);
	if (!map)
		return (NULL);
	while (s[i])
	{
		map[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}
