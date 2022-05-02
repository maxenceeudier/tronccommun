/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:11:27 by meudier           #+#    #+#             */
/*   Updated: 2022/05/02 16:26:28 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	if (!s1)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;
	int		size;

	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	join = (char *)malloc(sizeof(char) * size + 1);
	if (!join)
		return (NULL);
	j = 0;
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	return (join);
}
/*
#include <stdio.h>

int main()
{
char    s1[] = "coucou";
char    s2[] = " : mec";

printf("%s", ft_strjoin(s1, s2));
return (0);
}*/
