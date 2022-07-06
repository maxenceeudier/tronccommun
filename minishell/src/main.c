/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:55:05 by meudier           #+#    #+#             */
/*   Updated: 2022/07/04 15:37:15 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

char	*get_line(void)
{
	char		*line;
	char		*buf;
	char		*prompt;

	buf = getcwd(NULL, 0);
	prompt = ft_strjoin(buf, "$ ");
	line = readline(prompt);
	free(buf);
	free(prompt);
	return (line);
}

int	exit_shell(char *line, t_lexer *lst_lexer)
{
	free(line);
	lst_clear_lexer(lst_lexer);
	exit (0);
}

void	minishell(char *line, char **env)
{
	t_lexer		*lst_lexer;
	t_parser	*lst_parser;
	t_pipe_info	pipe_info;

	lst_lexer = lexer(line);
	if (ft_strcmp(lst_lexer->data, "exit") == 0)
		exit_shell(line, lst_lexer);
	pipe_info.pipes = get_pipes(lst_lexer, &(pipe_info.num_of_process));
	lst_parser = parser(lst_lexer, &pipe_info, env);
	execute(lst_parser, &pipe_info);
	add_history(line);
	lst_clear_parser(lst_parser);
	lst_clear_lexer(lst_lexer);
}

void	handler_sigint(int sig)
{
	(void)sig;	
}

int	main(int ac, char **av, char **env)
{
	char		*line;
	(void)av;
	//struct sigaction sa;
	
	//sa.sa_handler = &handler_sigint;
	//sigaction(SIGINT, &sa, NULL);
	while (1 && ac == 1)
	{

		line = get_line();
		if (!line)
			return (1);
		if (*line)
			minishell(line, env);
		free(line);
	}
	rl_clear_history();
	return (0);
}	
