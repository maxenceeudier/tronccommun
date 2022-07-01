/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:41:17 by maxenceeudi       #+#    #+#             */
/*   Updated: 2022/07/01 16:31:59 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	no_leaks(int *pids, char *cmd_path, t_pipe_info *pipe_info, t_parser *parser)
{
	free(pids);
	if (cmd_path)
		free(cmd_path);
    close_pipes(pipe_info);
	close_std(parser);
    lst_clear_parser(parser);
	return (0);
}

int    dup_fd(t_parser *parser)
{
    t_in    *last_in;

    last_in = parser->stdin;
    if (last_in)
    {
        while (last_in->next)
        {
            if (last_in->stdin < 0)
                return (0);
            last_in = last_in->next;
        }
        if (last_in->stdin < 0)
            return (0);
        if (last_in->stdin != 0)
            dup2(last_in->stdin, STDIN_FILENO);
    }
    if (parser->stdout != 1)
        dup2(parser->stdout, STDOUT_FILENO);
    return (1);
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

int	init_pid(int num_of_process, int **pids)
{
	*pids = (int *)calloc(sizeof(int), num_of_process + 1);
	if (!*pids)
	{
		printf("Error fork()");
		return (0);
	}
	return (1);
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