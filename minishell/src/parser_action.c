/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:47:27 by meudier           #+#    #+#             */
/*   Updated: 2022/07/04 12:11:54 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	redir_in(t_parser **new, t_lexer **lexer)
{
	t_in	*last_in;

	push_in(&((*new)->stdin), open((*lexer)->next->data, O_RDWR | O_APPEND));
	last_in = (*new)->stdin;
	while (last_in->next)
		last_in = last_in->next;
	if (last_in->stdin < 0)
		perror((*lexer)->next->data);
	(*lexer) = (*lexer)->next->next;
}

void	wrd(t_parser **new, t_lexer **lexer, t_pipe_info *pipe_info)
{
	int	i;

	if (pipe_info->in)
		push_in(&((*new)->stdin), pipe_info->in);
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

void	redir_out(t_parser **new, t_lexer **lexer, t_pipe_info *pipe_info)
{
	int	temp;

	temp = 0;
	if ((*lexer)->next->type == WRD)
	{
		temp = (*new)->stdout;
		(*new)->stdout = open((*lexer)->next->data, \
		O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if ((*new)->stdout < 0)
			perror((*lexer)->next->data);
		if (temp != 1 && is_not_a_pipe(temp, \
		pipe_info->pipes, pipe_info->num_of_process))
			close(temp);
		(*lexer) = (*lexer)->next->next;
	}
	else
		exit (1);
}

void	redir_out_append(t_parser **new, t_lexer **lexer, \
t_pipe_info *pipe_info)
{
	int	temp;

	temp = 0;
	if ((*lexer)->next->type == WRD)
	{	
		temp = (*new)->stdout;
		(*new)->stdout = open((*lexer)->next->data, \
		O_WRONLY | O_APPEND | O_CREAT, 0777);
		if ((*new)->stdout < 0)
			perror((*lexer)->next->data);
		if (temp != 1 && is_not_a_pipe(temp, \
		pipe_info->pipes, pipe_info->num_of_process))
			close(temp);
		(*lexer) = (*lexer)->next->next;
	}
	else
		exit (1);
}
