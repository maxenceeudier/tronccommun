/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:55:05 by meudier           #+#    #+#             */
/*   Updated: 2022/07/05 16:42:42 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

char	*get_line(void)
{
	char		*line;
	char		*buf;
	char		*prompt;
	char		*temp;
	t_env		*last;

	last = g_env;
	while (last)
	{
		if (ft_strcmp(last->key, "PWD") == 0)
			break ;
		last = last->next;
	}
	if (last)
		buf = ft_strdup(last->value);
	else
		buf = getcwd(NULL, 0);
	temp = ft_strjoin("\033[0;32m", buf);
	prompt = ft_strjoin(temp, "$ \033[0m");
	line = readline(prompt);
	free(buf);
	free(temp);
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

void handler_sigint(int sig)
{
	if (sig == SIGINT)
	{
		//rl_replace_line();
		write(1, "\n", 1);
		kill(getpid(), SIGCONT);
	}
	if (sig == SIGQUIT)
		printf("ok");
}

void	sig_init(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_RESTART;
	sa.__sigaction_u.__sa_handler = &handler_sigint;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	push_env(t_env **lst, char *str)
{
	t_env	*new;
	t_env	*last;
	char	**temp;

	new = (t_env *)malloc(sizeof(new));
	if (!new)
		exit(1);
	temp = ft_split(str, '=');
	new->key = temp[0];
	new->value = temp[1];
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_env	*get_env(char **env)
{
	int		i;
	t_env	*lst;

	lst = NULL;
	i = 0;
	while (env && env[i])
		push_env(&lst, env[i++]);
	return (lst);
}

int	main(int ac, char **av, char **env)
{
	char		*line;
	
	(void)av;
	g_env = get_env(env);
	sig_init();
	while (1 && ac == 1)
	{
		line = get_line();
		if (!line)
			return (1);
		if (*line)
			minishell(line, env);
		free(line);
	}
	clear_history();
	return (0);
}	
