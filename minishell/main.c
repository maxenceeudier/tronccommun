/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:55:05 by meudier           #+#    #+#             */
/*   Updated: 2022/06/28 08:21:06 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	push(t_lexer **lst, char *word, int TYPE)
{
	t_lexer *new;
	t_lexer	*last;
	
	new = (t_lexer *)malloc(sizeof(t_lexer *) * 2 + sizeof(char *) + sizeof(int));
	if (!new)
		return ;
	new->data = word;
	new->type = TYPE;
	new->prev = NULL;
	new->next = NULL;
	if (!*lst)
	{
		new->prev = NULL;
		*lst = new;
	}	
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

t_lexer	*lexer(char *line)
{
	char	**words;
	t_lexer	*lst;
	int		i;

	i = 0;
	lst = NULL;
	words = ft_split_lexer(line);
	while (words[i])
	{
		if (ft_strcmp(words[i], "|") == 0)
			push(&lst, words[i], PIPE);
		else if (ft_strcmp(words[i], "<") == 0)
			push(&lst, words[i], REDIR_IN);
		else if (ft_strcmp(words[i], ">") == 0)
			push(&lst, words[i], REDIR_IN);
		else if (ft_strcmp(words[i], ">>") == 0)
			push(&lst, words[i], REDIR_OUT_APPEND);
		else if (ft_strcmp(words[i], "<<") == 0)
			push(&lst, words[i], HERDOC);
		else
			push(&lst, words[i], WRD);
		i++;
	}
	return (lst);
}

int	main()
{
	char	*line;
	char	*buf;
	char	*prompt;
	t_lexer	*lst_lexer;

	while (1)
	{
		buf = getcwd(NULL, 0);
		prompt = ft_strjoin(buf, ": ");
		line = readline(prompt);
		free(buf);
		free(prompt);
		if (!line)
			break;
		if (*line)
		{
			lst_lexer = lexer(line);
			while (lst_lexer)
			{
				char *type;
				if (lst_lexer->type == 0)
					type = "PIPE";
				else if (lst_lexer->type == 1)
					type = "REDIR_OUT";
				else if (lst_lexer->type == 2)
					type = "REDIR_IN";
				else if (lst_lexer->type == 3)
					type = "REDIR_OUT_APPEND";
				else if (lst_lexer->type == 4)
					type = "HERDOC";
				else if (lst_lexer->type == 5)
					type = "WRD";
				if (lst_lexer->prev)
					printf("%s, type %s, prev: %s\n", lst_lexer->data, type, lst_lexer->prev->data);
				else 
					printf("%s, type %s, prev: %s\n", lst_lexer->data, type, "(null)");
				lst_lexer = lst_lexer->next;
			}
			add_history(line);
		}
		free(line);
	}
	clear_history();
	return (0);
}	
