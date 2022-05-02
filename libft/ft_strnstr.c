/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:49:00 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 15:56:19 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (needle[i])
		i++;
	if (!i)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && needle[j] && j < len)
				j++;
			if (j == len || !needle[j])
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
char    haystack[100] = "salutation comment ca va mon gars ?";
char    *occur;

occur = ft_strnstr(haystack, "ati", 1);
printf("%s", occur);
return (0);
}*/
