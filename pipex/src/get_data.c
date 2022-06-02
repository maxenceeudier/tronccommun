/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:36:16 by meudier           #+#    #+#             */
/*   Updated: 2022/06/02 14:55:53 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	get_file_fd(t_fds *files, char **av, int ac)
{
	files->in_file = open(av[1], O_RDONLY);
	if (files->in_file < 0)
	{
		ft_printf("pipex: no such file or directory: %s\n", av[1]);
		return (0);
	}
	files->out_file = open(av[ac - 1], O_WRONLY | O_CREAT, 0777);
	if (files->out_file < 0)
	{
		ft_printf("Can not open the out_file\n");
		return (0);
	}
	return (1);
}

int	**get_pipes(int num_of_process)
{
	int	i;
	int	**pipes;

	pipes = (int **)calloc(sizeof(int *), (num_of_process + 1));
	if (!pipes)
		return (0);
	i = 0;
	while (i < num_of_process + 1)
	{
		pipes[i] = (int *)calloc(sizeof(int), 2);
		if (!pipes[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < num_of_process + 1)
	{
		if (pipe(pipes[i]) == -1)
			return (0);
		i++;
	}
	return (pipes);
}
