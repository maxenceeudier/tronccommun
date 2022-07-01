/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:55:05 by meudier           #+#    #+#             */
/*   Updated: 2022/07/01 17:30:08 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	main(int ac, char **av, char **env)
{
	char		*line;
	char		*buf;
	char		*prompt;
	t_lexer		*lst_lexer;
	t_parser	*lst_parser;
	t_pipe_info	pipe_info;
	
	(void)ac;
	(void)av;
	while (1)
	{
		buf = getcwd(NULL, 0);
		prompt = ft_strjoin(buf, ": ");
		line = readline(prompt);
		free(buf);
		free(prompt);
		if (!line)
			return (1);
		if (*line)
		{
			lst_lexer = lexer(line);
			if (ft_strcmp(lst_lexer->data, "exit") == 0)
			{
				free(line);
				lst_clear_lexer(lst_lexer);
				break ;
			}
			pipe_info.pipes = get_pipes(lst_lexer, &(pipe_info.num_of_process));
			lst_parser = parser(lst_lexer, &pipe_info, env);
			execute(lst_parser, &pipe_info);
			add_history(line);
			lst_clear_parser(lst_parser);
			lst_clear_lexer(lst_lexer);
		}
		free(line);
	}
	clear_history();
	return (0);
}	


/****** print parser ******/
/*t_parser *temp = lst_parser;
t_in	*temp_in;
while (temp)
{
	printf("cmd: %s\n", temp->cmd);
	int i = 0;
	printf("arg : ");
	while (temp->arg && temp->arg[i])
		printf("%s ", temp->arg[i++]);
	printf("\nstdin: ");
	temp_in = temp->stdin;
	while (temp_in)
	{
		printf("%d ", temp_in->stdin);
		temp_in = temp_in->next;
	}
	printf("\nstdout: %d\n\n", temp->stdout);
	temp = temp->next;
}*/


/****** print lexer *******/
/*
while (lst_lexer)
{
	char *type;
	type = NULL;
	if (lst_lexer->type == 0)
		type = "PIPE";
	else if (lst_lexer->type == 1)
		type = "REDIR_OUT";
	else if (lst_lexer->type == 2)
	type = "REDIR_IN";
	else if (lst_lexer->type == 3)
		type = "REDIR_OUT_APPEND";
	else if (lst_lexer->type == 4)
		type = "HERDOC";
	else if (lst_lexer->type == 5)
		type = "WRD";
	else if (lst_lexer->type == 6)
		type = "EMPTY";
	printf("%s, type %s\n", lst_lexer->data, type);
	lst_lexer = lst_lexer->next;
}
exit(1);
*/