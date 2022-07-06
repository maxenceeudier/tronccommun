/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:55:05 by meudier           #+#    #+#             */
/*   Updated: 2022/07/06 10:26:17 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"


char	*get_line(void)
{
	char		*line;
	char		*buf;
	char		*prompt;
	char		*temp;

	buf = getcwd(NULL, 0);
	temp = ft_strjoin("\033[0;32m", buf);
	prompt = ft_strjoin(temp, "$ \033[0m");
	line = readline(prompt);
	free(buf);
	free(temp);
	free(prompt);
	return (line);
}

int	exit_shell(char *line, t_lexer *lst_lexer, t_env *envl)
{
	free(line);
	lst_clear_lexer(lst_lexer);
	lst_clear_envl(envl);
	rl_clear_history();
	exit (0);
}

void	minishell(char *line, t_env *envl)
{
	t_lexer		*lst_lexer;
	t_parser	*lst_parser;
	t_pipe_info	pipe_info;

	lst_lexer = lexer(line);
	if (ft_strcmp(lst_lexer->data, "exit") == 0)
		exit_shell(line, lst_lexer, envl);
	pipe_info.pipes = get_pipes(lst_lexer, &(pipe_info.num_of_process));
	lst_parser = parser(lst_lexer, &pipe_info);
	execute(lst_parser, &pipe_info, envl);
	add_history(line);
	lst_clear_parser(lst_parser);
	lst_clear_lexer(lst_lexer);
}

void handler_sigint(int sig)
{
	char		*buf;
	char		*prompt;
	char		*temp;

	if (sig == SIGINT)
	{
		buf = getcwd(NULL, 0);
		temp = ft_strjoin("\033[0;32m", buf);
		prompt = ft_strjoin(temp, "$ \033[0m");
		write(1, "\n", 1);
		write(1, prompt, ft_strlen(prompt));
		free(buf);
		free(temp);
		free(prompt);
	}
	if (sig == SIGQUIT)
		printf("ok");
}

void	sig_init(void)
{
	struct sigaction sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handler_sigint;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	get_key_value(char *str, char **key, char **value)
{
	int		i;
	int		len;

	len = 0;
	while (str[len] != '=')
		len++;
	*key = (char *)malloc(sizeof(char) * (len + 1));
	if (!*key)
		exit(0);
	i = 0;
	while (i < len)
	{
		(*key)[i] = str[i];
		i++;
	}
	(*key)[i] = 0;
	i++;
	len = ft_strlen(str) - i;
	*value = (char *)malloc(sizeof(char) * (len + 1));
	if (!*value)
		exit(0);
	len = 0;
	while (i < ft_strlen(str))
		(*value)[len++] = str[i++];
	(*value)[len] = 0;
}

void	push_env(t_env **lst, char *str)
{
	t_env	*new;
	t_env	*last;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		exit(1);
	get_key_value(str, &(new->key), &(new->value));
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

void	lst_clear_envl(t_env *envl)
{
	t_env *temp;

	while (envl)
	{
		temp = envl;
		envl = envl->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

int	main(int ac, char **av, char **env)
{
	char		*line;
	t_env		*envl;
	
	(void)av;
	envl = get_env(env);
	sig_init();
	while (1 && ac == 1)
	{
		line = get_line();
		if (!line)
			return (1);
		if (*line)
			minishell(line, envl);
		free(line);
	}
	return (0);
}	
