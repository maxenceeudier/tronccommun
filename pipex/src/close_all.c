/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:37:30 by meudier           #+#    #+#             */
/*   Updated: 2022/06/02 16:47:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_all_fd(int num_of_process, t_fds *fd)
{
	int	j;
	
	if (fd->in_file >= 0)
		close(fd->in_file);
	close(fd->out_file);
	j = 0;
	while (j < num_of_process + 1)
	{
		close(fd->pipes[j][0]);
		close(fd->pipes[j][1]);
		j++;
	}
}
