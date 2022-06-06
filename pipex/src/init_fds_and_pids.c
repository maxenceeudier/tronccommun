/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fds_and_pids.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:17:00 by meudier           #+#    #+#             */
/*   Updated: 2022/06/03 11:46:58 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	init_fd_pid(int num_of_process, t_fds *fd, t_exec *vars, int **pids)
{
	if (!get_file_fd(fd, vars->av, num_of_process + 3))
		return (0);
	*pids = (int *)calloc(sizeof(int), num_of_process + 1);
	if (!*pids)
	{
		ft_printf("Error fork()");
		return (0);
	}
	return (1);
}
