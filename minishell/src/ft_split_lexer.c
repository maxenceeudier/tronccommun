/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:02:00 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/06/28 08:18:34 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int isMeta(char c, char *meta)
{
    int i = 0;

    while (meta[i])
    {
        if (meta[i] == c)
            return (1);
        i++;
    }
    return (0);
}

static int	ft_get_size(char const *s)
{
	int	    i;
    int     j;
	int	    count;
    char    *meta;

    meta = "><|\'\"";
	count = 0;
	i = 0;
	while (s[i])
	{
        j = 0;
		while (s[i] == ' ' && s[i])
			i++;
        while (meta[j])
        {
            if (j < 3 && s[i] == meta[j] && s[i])
            {
                count++;
                while (s[i] == meta[j] && s[i])
                    i++;
                break ;
            }
            else if (s[i] == meta[j] && s[i])
            {
                count++;
                i++;
                while (s[i] != meta[j] && s[i])
                    i++;
                break ;
            }
            else if (s[i] != ' ' && !isMeta(s[i], meta))
            {
                count++;
                while (s[i] != ' ' && !isMeta(s[i], meta) && s[i])
                    i++;
                break ;
            }
            j++;
        }
	}
	return (count);
}

static char	*ft_get_word(int *index, char *s)
{
	char	*word;
    char    *meta;
	int		len;
	int		i;
    int     j;

	len = 0;
    j = 0;
    meta = "><|\'\"";
	while (s[*index] == ' ' && s[*index])
		(*index)++;
    while (meta[j])
    {
        if (j < 3 && s[*index] == meta[j] && s[*index])
            {
                while (s[*index + len] == meta[j] && s[*index + len])
                    len++;
                break ;
            }
            else if (s[*index] == meta[j] && s[*index])
            {
                len++;
                while (s[*index + len] != meta[j] && s[*index + len])
                    len++;
                len++;
                break ;
            }
            else if (s[*index] != ' ' && !isMeta(s[*index], meta))
            {
                while (s[*index + len] != ' ' && !isMeta(s[*index + len], meta) && s[*index + len])
                    len++;
                break ;
            }
        j++;
    }
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

char	**clear_tab(char **tab)
{
	int		i;

	i = 0;
	while ((tab)[i])
		free((tab)[i++]);
	free (tab);
	return (NULL);
}

char	**ft_split_lexer(char const *s)
{
	int		i;
	int		j;
	int		size;
	char	**tab;

	if (!s)
		return (NULL);
	size = ft_get_size(s);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		tab[i] = ft_get_word(&j, (char *)s);
		if (!tab[i])
			return (clear_tab(tab));
		i++;
	}
	tab[i] = 0;
	return (tab);
}
