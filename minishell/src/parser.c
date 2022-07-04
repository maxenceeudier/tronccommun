/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:05:26 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/04 09:27:21 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	push_in(t_in **stdin, int data)
{
	t_in	*new;
	t_in	*last; 

	new = (t_in *)ft_calloc(sizeof(t_in), 1);
	if (!new)
		exit(1) ;
	new->stdin = data;
	new->next = NULL;
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

void	init_parser(t_parser *new, char **env)
{
	new->cmd = NULL;
	new->stdin = NULL;
	new->env = env;
	new->stdout = 1;
	new->next = NULL;
	new->prev = NULL;
}

char	*get_arg(char *str)
{
	int		i;
	int		len;
	char	*arg;

	i = 0;
	len = ft_strlen(str);
	arg = (char *)ft_calloc(sizeof(char), len + 1);
	if (!arg)
		exit (1);
	while (str[i])
	{
		arg[i] = str[i];
		i++;
	}
	arg[i] = 0;
	return (arg);
}

void	create_new(t_parser **new, t_lexer **lexer, t_pipe_info *pipe_info)
{
	int		temp;
	int		i;
	t_in	*last_in;

	temp = 0;
	while ((*lexer) && (*lexer)->type != PIPE)
	{
		if ((*lexer)->type == REDIR_IN && (*lexer)->next)
		{
			push_in(&((*new)->stdin) , open((*lexer)->next->data, O_RDONLY));
			last_in = (*new)->stdin;
			while (last_in->next)
				last_in = last_in->next;
			if (last_in->stdin < 0)
				perror((*lexer)->next->data);
			(*lexer) = (*lexer)->next->next;
		}
		else if ((*lexer)->type == WRD)
		{
			if (pipe_info->in)
				push_in(&((*new)->stdin) , pipe_info->in);
			if (pipe_info->out && (*new)->stdout == 1)
				(*new)->stdout = pipe_info->out;
			(*new)->cmd = (*lexer)->data;
			(*new)->arg = ft_calloc(sizeof(char *), (get_num_of_arg(*lexer) + 1));
			if (!(*new)->arg)
				exit (1);
			i = 0;
			while ((*lexer) && (*lexer)->type == WRD)
			{
				(*new)->arg[i++] = get_arg((*lexer)->data);
				(*lexer) = (*lexer)->next;
			}
			(*new)->arg[i] = NULL;
		}
		else if ((*lexer)->type == REDIR_OUT && (*lexer)->next)
		{
			if ((*lexer)->next->type == WRD)
			{
				temp = (*new)->stdout;
				(*new)->stdout = open((*lexer)->next->data, O_WRONLY | O_TRUNC | O_CREAT, 0777);
				if ((*new)->stdout < 0)
					perror((*lexer)->next->data);
				if (temp != 1 && is_not_a_pipe(temp, pipe_info->pipes, pipe_info->num_of_process))
					close(temp);
				(*lexer) = (*lexer)->next->next;
			}
			else
				exit (0);
		}
		else if ((*lexer)->type == REDIR_OUT_APPEND && (*lexer)->next)
		{
			if ((*lexer)->next->type == WRD)
			{	
				temp = (*new)->stdout;
				(*new)->stdout = open((*lexer)->next->data, O_WRONLY | O_APPEND | O_CREAT, 0777);
				if ((*new)->stdout < 0)
					perror((*lexer)->next->data);
				if (temp != 1 && is_not_a_pipe(temp, pipe_info->pipes, pipe_info->num_of_process))
					close(temp);
				(*lexer) = (*lexer)->next->next;
			}
			else
				exit (1);
		}
		else if ((*lexer)->type == HERDOC && (*lexer)->next)
		{
			push_in(&((*new)->stdin) , -2);
			(*lexer) = (*lexer)->next->next;
		}
		else if ((*lexer)->type == EMPTY)
			(*lexer) = (*lexer)->next;
	}
}

void	push_parser(t_parser **parser, t_lexer **lexer, t_pipe_info *pipe_info, char **env)
{
	t_parser	*new;
	t_parser	*last;

	new = (t_parser *)ft_calloc(sizeof(t_parser), 1);
	if (!new)
		exit (1);
	init_parser(new, env);
	create_new(&new, lexer, pipe_info);
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

t_parser	*parser(t_lexer *lexer, t_pipe_info *pipe_info, char **env)
{
	t_parser	*parser;
	int			j;

	parser = NULL;
	j = 0;
	while (lexer)
	{
		if (lexer->type != PIPE)
		{
			if (pipe_info->pipes && j != 0)
				pipe_info->in = pipe_info->pipes[j][0];
			else
				pipe_info->in = 0;
			if (pipe_info->pipes && j != pipe_info->num_of_process -1)
				pipe_info->out = pipe_info->pipes[j + 1][1];
			else
				pipe_info->out = 0;
			j++;
			push_parser(&parser, &lexer, pipe_info, env);
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

	while (parser)
	{
		temp = parser;
		parser = parser->next;
		temp->cmd = NULL;
		clear_tab(temp->arg);
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