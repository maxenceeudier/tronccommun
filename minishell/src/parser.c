/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:05:26 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/06/29 18:14:28 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	push_in(t_in **stdin, int data)
{
	t_in	*new;
	t_in	*last; 

	new = (t_in *)malloc(sizeof(t_in *));
	if (!new)
		exit(1) ;
	new->stdin = data;
	if (!*stdin)
		*stdin = new;
	else
	{
		last = *stdin;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	init_parser(t_parser *new)
{
	new->cmd = NULL;
	new->stdin = NULL;
	new->stdout = 1;
	new->next = NULL;
}

void	push_parser(t_parser **parser, t_lexer **lexer, int in, int out, int **pipes, int num_of_process)
{
	t_parser	*new;
	t_parser	*last;
	int			i;
	int			temp;

	new = (t_parser *)malloc(sizeof(t_parser *) * 2 + sizeof(char *) + sizeof(int) * 2 + sizeof(char **));
	if (!new)
		return ;
	init_parser(new);
	while ((*lexer) && (*lexer)->type != PIPE)
	{
		if ((*lexer)->type == REDIR_IN)
		{
			push_in(&new->stdin , open((*lexer)->next->data, O_RDONLY));
			if ((*lexer)->next)
				(*lexer) = (*lexer)->next->next;
		}
		else if ((*lexer) && (*lexer)->type == WRD)
		{
			if (in)
			{
				push_in(&new->stdin , in);
			}
			if (out)
			{
				if (new->stdout == 1)
					new->stdout = out;
			}	
			new->cmd = (*lexer)->data;
			(*lexer) = (*lexer)->next;
			i = 0;
			new->arg = malloc(sizeof(char *) * (get_num_of_arg(*lexer) + 1));
			if (!new->arg)
				return ;
			while ((*lexer) && (*lexer)->type == WRD)
			{
				new->arg[i++] = (*lexer)->data;
				(*lexer) = (*lexer)->next;
			}
			new->arg[i] = NULL;
		}
		else if ((*lexer)->type == REDIR_OUT)
		{
			if ((*lexer)->next && (*lexer)->next->type == WRD)
			{
				temp = new->stdout;
				new->stdout = open((*lexer)->next->data, O_RDONLY | O_TRUNC | O_CREAT, 0777);
				if (temp != 1 && is_not_a_pipe(temp, pipes, num_of_process))
					close(temp);
				(*lexer) = (*lexer)->next->next;
			}
			else
				return ;
		}
		else if ((*lexer)->type == REDIR_OUT_APPEND)
		{
			if ((*lexer)->next && (*lexer)->next->type == WRD)
			{	
				temp = new->stdout;
				new->stdout = open((*lexer)->next->data, O_RDONLY | O_APPEND | O_CREAT, 0777);
				if (temp != 1 && is_not_a_pipe(temp, pipes, num_of_process))
					close(temp);
				(*lexer) = (*lexer)->next->next;
			}
			else
				return ;
		}
	}
	if (!*parser)
	{
		new->prev = NULL;
		*parser = new;
	}	
	else
	{
		last = *parser;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

t_parser	*parser(t_lexer *lexer, int **pipes, int num_of_process)
{
	t_parser	*parser;
	int			j;
	int			in;
	int			out;

	parser = NULL;
	j = 0;
	while (lexer)
	{
		if (lexer->type != PIPE)
		{
			if (pipes && j != 0)
				in = pipes[j][0];
			else
				in = 0;
			if (pipes && j != num_of_process -1)
				out = pipes[j + 1][1];
			else
				out = 0;
			j++;
			push_parser(&parser, &lexer, in, out, pipes, num_of_process);
		}	
		else
			lexer = lexer->next;
	}
	return (parser);
}

void	lst_clear_parser(t_parser *parser)
{
	t_parser	*temp;
	t_in		*temp_in;
	int			i;

	i = 0;
	while (parser)
	{
		temp = parser;
		parser = parser->next;
		temp->cmd = NULL;
		free(temp->arg);
		while (temp->stdin)
		{
			temp_in = temp->stdin;
			temp->stdin = temp->stdin->next;
			temp_in->stdin = 0;
			free(temp_in);
		}
		temp->stdout = 0;
		free(temp);
	}
}