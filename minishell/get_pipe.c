/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:39:27 by meudier           #+#    #+#             */
/*   Updated: 2022/06/28 15:26:42 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int get_num_of_process(t_lexer *lexer)
{
    t_lexer *lst;
    int     count;

    count = 1;
    lst = lexer;
    while (lst)
    {
        if (lst->type == PIPE)
            count++;
        lst = lst->next;
    }
    return (count);
}

int	**get_pipes(t_lexer *lexer, int *num_of_process)
{
	int	i;
	int	**pipes;
    
    *num_of_process = get_num_of_process(lexer);
	pipes = (int **)calloc(sizeof(int *), (*num_of_process));
	if (!pipes || *num_of_process == 1)
		return (0);
	i = 0;
	while (i < *num_of_process)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipes[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < *num_of_process)
	{
		if (pipe(pipes[i]) == -1)
			return (0);
		i++;
	}
	return (pipes);
}