/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:41:17 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/04 09:30:14 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	no_leaks(int *pids, char *cmd_path, t_pipe_info *pipe_info, t_parser *parser)
{
	free(pids);
	if (cmd_path)
		free(cmd_path);
	if (pipe_info->pipes)
    	close_pipes(pipe_info);
	close_std(parser);
    lst_clear_parser(parser);
	return (0);
}

void	init_pid(int num_of_process, int **pids)
{
	*pids = (int *)ft_calloc(sizeof(int), num_of_process + 1);
	if (!*pids)
		exit (1);
}

void	exec_cmd(t_parser *parser,int *pids, t_pipe_info *pipe_info, int i)
{
    char *cmd_path;
    
	if (!get_cmdpath(parser, &cmd_path, i))
		exit(no_leaks(pids, cmd_path, pipe_info, parser));
	if (!dup_fd(parser))
	{
		cmd_path = NULL;
		exit(no_leaks(pids, cmd_path, pipe_info, parser));
	}
	close_pipes(pipe_info);
	close_std(parser);
	execve(cmd_path, parser->arg, NULL);
	write_error(parser->cmd);
    exit(no_leaks(pids, cmd_path, pipe_info, parser));
}

int	execute(t_parser *parser, t_pipe_info *pipe_info)
{
	int	*pids;
	int	i;

	init_pid(pipe_info->num_of_process, &pids);
	i = 0;
	while (i < pipe_info->num_of_process && parser)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (0);
		if (pids[i] == 0)
			exec_cmd(parser, pids, pipe_info, i);
        parser = parser->next;
		i++;
	}
	close_pipes(pipe_info);
	close_std(parser);
	i = 0;
	while (pids[i])
	{
		wait(NULL);
		i++;
	}
	free(pids);
	return (1);
}