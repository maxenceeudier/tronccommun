/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:06:31 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 14:02:50 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			size;

	size = 0;
	i = start;
	while (s[i])
	{
		i++;
		size++;
	}
	if (size > len)
		return (len);
	else
		return (size);
}	

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new = (char *)malloc(1);
		new[0] = 0;
		return (new);
	}
	size = get_size(s, start, len);
	i = 0;
	new = (char *)malloc(size + 1);
	if (!new)
		return (NULL);
	while (s[start] && i < size)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = 0;
	return (new);
}
/*
#include <stdio.h>

int main()
{
char s[]= "salut mec ca marche ou pas ?";
printf("%s", ft_substr(s, 100, 4));
return (0);
}*/
