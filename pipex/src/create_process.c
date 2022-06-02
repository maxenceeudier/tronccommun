/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:34:48 by meudier           #+#    #+#             */
/*   Updated: 2022/06/02 14:55:33 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd(t_exec *vars, int *pids, t_fds *fd, int i)
{
	if (!get_path_and_arg(vars, i))
	{
		free(pids);
		exit(0);
	}
	dup_fd(i, vars->num_of_process, fd);
	close_all_fd(vars->num_of_process, fd);
	free(pids);
	execve(vars->cmd_path, vars->arg, NULL);
	ft_printf("Eroor exec\n");
	exit(0);
}

int	create_process(t_fds *fd, t_exec *vars)
{
	int	*pids;
	int	i;

	if (!init_fd_pid(vars->num_of_process, fd, vars, &pids))
		return (0);
	i = 0;
	while (i < vars->num_of_process)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (0);
		if (pids[i] == 0)
			exec_cmd(vars, pids, fd, i);
		i++;
	}
	close_all_fd(vars->num_of_process, fd);
	i = 0;
	while (pids[i])
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
	free(pids);
	return (1);
}
