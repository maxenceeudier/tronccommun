/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:13:40 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/06/29 18:14:35 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	close_std(t_parser *parser)
{
	t_parser	*last;
	t_in		*last_in;

	last = parser;
	while(last)
	{
		if (last->stdout != 1)
			close(last->stdout);
		last_in = last->stdin;
		while (last_in)
		{
			if (last_in != 0)
				close (last_in->stdin);
			last_in = last_in->next;
		}
		last = last->next;
	}
}

void	close_pipes(int **pipes, int num_of_process)
{
	int	i;

	i = 0;
	printf("pipes: ");
	while (pipes && i < num_of_process)
	{
		printf("%d, %d\n", pipes[i][0], pipes[i][1]);
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}