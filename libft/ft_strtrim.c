/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:18:16 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 17:41:56 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
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

static int	get_count_start(char const *s1, char const *set)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	while (s1[i] == set[0])
	{
		len = 0;
		while (s1[i] == set[len] && set[len])
		{
			len++;
			i++;
		}
		if (!set[len])
			count++;
	}
	return (count);
}

static int	get_count_end(char const *s1, char const *set)
{
	int	i;
	int	len;
	int	count;

	i = ft_strlen(s1);
	len = ft_strlen(set);
	count = 0;
	while (s1[i - 1] == set[len - 1])
	{
		while (s1[i - 1] == set[len - 1] && len >= 1)
		{
			i--;
			len--;
		}
		if (len == 0)
			count++;
		len = ft_strlen(set);
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		count_start;
	int		count_end;
	char	*trim;

	count_start = get_count_start(s1, set);
	count_end = get_count_end(s1, set);
	len = ft_strlen(set);
	trim = ft_substr(s1, len * count_start,
			ft_strlen(s1) - (count_start + count_end) * len + 1);
	if (!trim)
		return (NULL);
	return (trim);
}
/*
   int main()
   {
   char    s1[] = "yoyo..coucou mec..yoyoyo";
   printf("%s", ft_strtrim(s1, "yo"));
   return (0);
   }*/
