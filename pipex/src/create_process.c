/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:34:48 by meudier           #+#    #+#             */
/*   Updated: 2022/06/09 17:43:03 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	no_leaks(int *pids, t_exec *vars, t_fds *fd)
{
	free(pids);
	free_tab_int(fd->pipes, vars->num_of_process + 1);
	if (vars->cmd_path)
		free(vars->cmd_path);
	return (0);
}

void	exec_cmd(t_exec *vars, int *pids, t_fds *fd, int i)
{
	if (!get_path_and_arg(vars, i, fd))
		exit(no_leaks(pids, vars, fd));
	if (!dup_fd(i, vars->num_of_process, fd))
	{
		free_tab(vars->arg);
		exit(no_leaks(pids, vars, fd));
	}
	close_all_fd(vars->num_of_process, fd);
	execve(vars->cmd_path, vars->arg, vars->env);
	write_error(vars->cmd[0]);
	free_tab(vars->cmd);
	free(pids);
	free_tab_int(fd->pipes, vars->num_of_process + 1);
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
		wait(NULL);
		i++;
	}
	free(pids);
	return (1);
}
