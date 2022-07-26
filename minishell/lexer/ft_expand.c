/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:54:44 by ammah             #+#    #+#             */
/*   Updated: 2022/07/25 15:42:05 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	get_size_word_expand(char *word, int *i, t_vars *vars)
{
	int		size_var;
	int		size;

	size = 0;
	(*i)++;
	if (ft_strncmp(word + *i, "\"\"", 2) == 0
		|| ft_strncmp(word + *i, "\'\'", 2) == 0)
	{
		*i = *i + 2;
		return (0);
	}
	if (*(word + *i) == '?')
	{
		(*i)++;
		return (get_size_nb(vars->exit_code));
	}
	while (*(word + *i + size) && (ft_isalnum(*(word + *i + size))
			|| *(word + *i + size) == '_'))
		size++;
	size_var = ft_strlen(get_var(word + *i, vars, size));
	*i += size;
	return (size_var);
}

int	size_simple_quote(char *word, int *i)
{
	int	size;

	size = 0;
	(*i)++;
	while (*(word + *i) && *(word + *i) != '\'')
	{
		size++;
		(*i)++;
	}
	if (*(word + *i) == '\'')
		(*i)++;
	return (size);
}

int	size_double_quote(char *word, int *i, t_vars *vars)
{
	int	size;

	size = 0;
	(*i)++;
	while (*(word + *i) && *(word + *i) != '\"')
	{
		if (*(word + *i) == '$' && *(word + *i + 1)
			&& (ft_isalnum(*(word + *i + 1)) || *(word + *i + 1) == '_'
				|| *(word + *i + 1) == '?'))
			size += get_size_word_expand(word, i, vars);
		else
		{
			(*i)++;
			size++;
		}
	}
	if (*(word + *i) == '\"')
		(*i)++;
	return (size);
}

int	get_size_expand(char **word, t_vars *vars)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (*word && (*word)[i])
	{
		if ((*word)[i] == '\'')
			size += size_simple_quote(*word, &i);
		else if ((*word)[i] == '\"')
		{
			size += size_double_quote(*word, &i, vars);
		}
		else
		{
			size++;
			i++;
		}
	}
	return (size);
}

void	ft_expand(char **words, t_vars *vars, t_lexer *lst)
{
	int		size;

	size = get_size_expand(words, vars);
	get_expand(words, vars, size, lst);
}
