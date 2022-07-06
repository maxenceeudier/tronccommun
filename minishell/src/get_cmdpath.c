/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:40:26 by meudier           #+#    #+#             */
/*   Updated: 2022/07/06 11:50:00 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	get_path(t_parser *parser, char ***path, t_env *envl)
{
	t_env	*last;

	*path = NULL;
	if (!parser->cmd)
		return (0);
	last = envl;
	while (last && ft_strcmp(last->key, "PATH") != 0)
		last = last->next;
	if (last)
		*path = ft_split(last->value, ':');
	else
		return (0);
	if (!*path)
		return (0);
	return (1);
}

static int	no_leaks(char **path)
{
	clear_tab(path);
	return (0);
}

int	get_cmd_path(char *cmd, char **cmd_path, char **path)
{
	char	*temp;
	int		j;

	*cmd_path = NULL;
	j = 0;
	while (path[j])
	{
		temp = *cmd_path;
		*cmd_path = ft_strjoin_bs(path[j], cmd);
		free (temp);
		if (!cmd_path)
			return (no_leaks(path));
		if (!access(*cmd_path, F_OK | X_OK))
			break ;
		j++;
	}
	if (!access(cmd, F_OK | X_OK))
	{
		free(*cmd_path);
		*cmd_path = cmd;
	}
	clear_tab(path);
	return (1);
}

int	all_stdin_pos(t_in *stdin)
{
	t_in	*last;

	last = stdin;
	while (last)
	{
		if (last->stdin < 0)
			return (0);
		last = last->next;
	}
	return (1);
}

int	get_cmdpath(t_parser *parser, char **cmd_path, int i, t_env *envl)
{
	char	**path;

	*cmd_path = NULL;
	if (!get_path(parser, &path, envl))
	{
		if (i || (!i && all_stdin_pos(parser->stdin)))
			write_error(parser->cmd);
		return (0);
	}
	if (!get_cmd_path(parser->cmd, cmd_path, path))
		return (0);
	if (access(*cmd_path, F_OK | X_OK) == -1)
	{
		if (i || (!i && all_stdin_pos(parser->stdin)))
			write_error(parser->cmd);
		return (0);
	}
	return (1);
}
