/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:34:59 by meudier           #+#    #+#             */
/*   Updated: 2022/05/18 08:55:38 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	nb;
	int			sign;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	sign = 1;
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

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (0);
	return (1);
}

static int	ft_get_size(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	*ft_get_word(int *index, char *s, char c)
{
	char	*word;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[*index] == c && s[*index])
		(*index)++;
	while (s[*index + len] != c && s[*index + len])
		len ++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*index];
		(*index)++;
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	char	**tab;

	if (!s)
		return (NULL);
	size = ft_get_size(s, c);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		tab[i] = ft_get_word(&j, (char *)s, c);
		if (!tab[i])
		{
			clear_tab(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}
