/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:18:16 by meudier           #+#    #+#             */
/*   Updated: 2022/05/04 13:50:25 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_count_start(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (is_charset(s1[i], set))
	{
		count++;
		i++;
	}
	return (count);
}

static int	get_count_end(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = ft_strlen(s1);
	count = 0;
	while (is_charset(s1[i - 1], set))
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		count_start;
	int		count_end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	count_start = get_count_start(s1, set);
	count_end = get_count_end(s1, set);
	trim = ft_substr(s1, count_start,
			ft_strlen(s1) - (count_start + count_end));
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
