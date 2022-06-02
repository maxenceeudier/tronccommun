/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_and_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:40:26 by meudier           #+#    #+#             */
/*   Updated: 2022/06/02 16:40:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	get_path(t_exec *vars, int i)
{
	int	j;

	vars->cmd = ft_split(vars->av[i + 2], ' ');
	if (!vars->cmd)
		return (0);
	j = 0;
	while (ft_strncmp(vars->env[j], "PATH", 4))
		j++;
	vars->path = ft_split(vars->env[j] + 5, ':');
	if (!vars->path)
	{
		free_tab(vars->cmd);
		return (0);
	}
	return (1);
}

int	get_cmd_path(t_exec *vars)
{
	char	*temp;
	int		j;

	vars->cmd_path = NULL;
	j = 0;
	while (vars->path[j])
	{
		temp = vars->cmd_path;
		vars->cmd_path = ft_strjoin(vars->path[j], vars->cmd[0]);
		free (temp);
		if (!vars->cmd_path)
		{
			free_tab(vars->cmd);
			free_tab(vars->path);
			return (0);
		}
		if (!access(vars->cmd_path, F_OK | X_OK))
			break ;
		j++;
	}
	free_tab(vars->path);
	return (1);
}

int	get_path_and_arg(t_exec *vars, int i)
{
	if (!get_path(vars, i))
		return (0);
	if (!get_cmd_path(vars))
		return (0);
	if (access(vars->cmd_path, F_OK | X_OK) == -1)
	{
		ft_printf("The cmd %s do not exist\n", vars->cmd_path);
		
		free_tab(vars->cmd);
		return (0);
	}
	vars->arg = vars->cmd;
	return (1);
}
