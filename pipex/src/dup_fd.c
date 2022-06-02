/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:57:17 by meudier           #+#    #+#             */
/*   Updated: 2022/06/02 16:21:16 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	dup_fd(int i, int num_of_process, t_fds *fd)
{
	if (i == 0)
	{
		if (fd->in_file < 0)
			return (0);
		dup2(fd->in_file, STDIN_FILENO);
	}	
	else
		dup2(fd->pipes[i + 1][0], STDIN_FILENO);
	if (i == num_of_process - 1)
		dup2(fd->out_file, STDOUT_FILENO);
	else
		dup2(fd->pipes[i + 2][1], STDOUT_FILENO);
	return (1);
}
