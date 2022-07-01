/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_and_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:40:26 by meudier           #+#    #+#             */
/*   Updated: 2022/07/01 15:56:55 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	get_path(t_exec *vars, int i)
{
	int	j;

	vars->cmd = ft_split(vars->av[i + 2], ' ');
	if (!vars->cmd || !vars->env)
		return (0);
	j = 0;
	while (vars->env[j] && ft_strncmp(vars->env[j], "PATH", 4))
		j++;
	if (vars->env[j])
		vars->path = ft_split(vars->env[j] + 5, ':');
	else
	{
		vars->cmd_path = NULL;
		return (0);
	}
	if (!vars->path)
		return (0);
	return (1);
}

static int	no_leaks(t_exec *vars)
{
	free_tab(vars->cmd);
	free_tab(vars->path);
	return (0);
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
		vars->cmd_path = ft_strjoin_bs(vars->path[j], vars->cmd[0]);
		free (temp);
		if (!vars->cmd_path)
			return (no_leaks(vars));
		if (!access(vars->cmd_path, F_OK | X_OK))
			break ;
		j++;
	}
	if (!access(vars->cmd[0], F_OK | X_OK))
	{
		free(vars->cmd_path);
		vars->cmd_path = vars->cmd[0];
	}
	free_tab(vars->path);
	return (1);
}

void	write_error(char *cmd)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin("pipex: command not found: ", cmd);
	temp2 = ft_strjoin(temp1, "\n");
	free(temp1);
	write (2, temp2, 29 + ft_strlen(cmd));
	free(temp2);
}

int	get_path_and_arg(t_exec *vars, int i)
{
	if (!get_path(vars, i))
	{
		if (i || (!i)) // manque condition si infile >= 0
			write_error(vars->cmd[0]);
		free_tab(vars->cmd);
		return (0);
	}
	if (!get_cmd_path(vars))
		return (0);
	if (access(vars->cmd_path, F_OK | X_OK) == -1)
	{
		write_error(vars->cmd[0]);
		free_tab(vars->cmd);
		return (0);
	}
	vars->arg = vars->cmd;
	return (1);
}
