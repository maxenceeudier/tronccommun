/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:06:31 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 16:11:02 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(len);
	if (!new)
		return (NULL);
	while (s[start] && i < len - 1 && len)
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
printf("%s", ft_substr(s, 6, 4));
return (0);
}*/
