/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:55:05 by meudier           #+#    #+#             */
/*   Updated: 2022/06/28 16:07:33 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	push_lexer(t_lexer **lst, char *word, int TYPE)
{
	t_lexer *new;
	t_lexer	*last;
	
	new = (t_lexer *)malloc(sizeof(t_lexer *) * 2 + sizeof(char *) + sizeof(int));
	if (!new)
		return ;
	new->data = word;
	new->type = TYPE;
	new->prev = NULL;
	new->next = NULL;
	if (!*lst)
	{
		new->prev = NULL;
		*lst = new;
	}	
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

t_lexer	*lexer(char *line)
{
	char	**words;
	t_lexer	*lst;
	int		i;

	i = 0;
	lst = NULL;
	words = ft_split_lexer(line);
	while (words[i])
	{
		if (ft_strcmp(words[i], "|") == 0)
			push_lexer(&lst, words[i], PIPE);
		else if (ft_strcmp(words[i], "<") == 0)
			push_lexer(&lst, words[i], REDIR_IN);
		else if (ft_strcmp(words[i], ">") == 0)
			push_lexer(&lst, words[i], REDIR_OUT);
		else if (ft_strcmp(words[i], ">>") == 0)
			push_lexer(&lst, words[i], REDIR_OUT_APPEND);
		else if (ft_strcmp(words[i], "<<") == 0)
			push_lexer(&lst, words[i], HERDOC);
		else
			push_lexer(&lst, words[i], WRD);
		i++;
	}
	return (lst);
}

void	init_parser(t_parser *new)
{
	new->cmd = NULL;
	new->stdin = 0;
	new->stdout = 1;
	new->next = NULL;
}

int	get_num_of_arg(t_lexer *lexer)
{
	t_lexer	*temp;
	int		i;

	i = 0;
	temp = lexer;
	while (temp && temp->type == WRD)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	push_parser(t_parser **parser, t_lexer **lexer, int in, int out)
{
	t_parser	*new;
	t_parser	*last;
	int			i;
	
	new = (t_parser *)malloc(sizeof(t_parser *) * 2 + sizeof(char *) + sizeof(int) * 2 + sizeof(char **));
	if (!new)
		return ;
	init_parser(new);
	while ((*lexer) && (*lexer)->type != PIPE)
	{
		if ((*lexer)->type == REDIR_IN)
		{
			new->stdin = open((*lexer)->next->data, O_RDONLY);
			if ((*lexer)->next)
				(*lexer) = (*lexer)->next->next;
		}
		else if ((*lexer) && (*lexer)->type == WRD)
		{
			if (in)
				new->stdin = in;
			if (out)
				new->stdout = out;
			
			new->cmd = (*lexer)->data;
			(*lexer) = (*lexer)->next;
			i = 0;
			new->arg = malloc(sizeof(char *) * (get_num_of_arg(*lexer) + 1));
			if (!new->arg)
				return ;
			while ((*lexer) && (*lexer)->type == WRD)
			{
				new->arg[i++] = (*lexer)->data;
				(*lexer) = (*lexer)->next;
			}
			new->arg[i] = NULL;
		}
		else if ((*lexer)->type == REDIR_OUT)
		{
			if ((*lexer)->next && (*lexer)->next->type == WRD)
			{
				if (!out)
					new->stdout = open((*lexer)->next->data, O_RDONLY | O_TRUNC | O_CREAT, 0777);
				(*lexer) = (*lexer)->next->next;
			}
			else
				return ;
		}
		else if ((*lexer)->type == REDIR_OUT_APPEND)
		{
			if ((*lexer)->next && (*lexer)->next->type == WRD)
			{
				if (!out)
					new->stdout = open((*lexer)->next->data, O_RDONLY | O_APPEND | O_CREAT, 0777);
				(*lexer) = (*lexer)->next->next;
			}
			else
				return ;
		}
	}
	if (!*parser)
	{
		new->prev = NULL;
		*parser = new;
	}	
	else
	{
		last = *parser;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

t_parser	*parser(t_lexer *lexer)
{
	t_parser	*parser;
	int			num_of_process;
	int			j;
	int			**pipes;
	int			in;
	int			out;

	pipes = get_pipes(lexer, &num_of_process);
	/*int i = 0;
	while (i < 4)
	{
		printf("%d, %d\n", pipes[i][0], pipes[i][1]);
		i++;
	}*/
	parser = NULL;
	j = 0;
	while (lexer)
	{
		if (lexer->type != PIPE)
		{
			if (pipes && j != 0)
				in = pipes[j][0];
			else
				in = 0;
			if (pipes && j != num_of_process -1)
				out = pipes[j + 1][1];
			else
				out = 0;
			j++;
			push_parser(&parser, &lexer, in, out);
		}	
		else
			lexer = lexer->next;
	}
	return (parser);
}

int	main()
{
	char		*line;
	char		*buf;
	char		*prompt;
	t_lexer		*lst_lexer;
	t_parser	*lst_parser;

	while (1)
	{
		buf = getcwd(NULL, 0);
		prompt = ft_strjoin(buf, ": ");
		line = readline(prompt);
		free(buf);
		free(prompt);
		if (!line)
			break;
		if (*line)
		{
			lst_lexer = lexer(line);
			lst_parser = parser(lst_lexer);
			while (lst_parser)
			{
				printf("cmd: %s\n", lst_parser->cmd);
				int i = 0;
				printf("arg : ");
				while (lst_parser->arg[i])
					printf("%s ", lst_parser->arg[i++]);
				printf("\nstdin: %d\nstdout: %d\n\n", lst_parser->stdin, lst_parser->stdout);
				lst_parser = lst_parser->next;
			}
			(void)lst_parser;
			add_history(line);
		}
		free(line);
	}
	clear_history();
	return (0);
}	

/****** print lexer *******/


			/*while (lst_lexer)
			{
				char *type;
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
				printf("%s, type %s\n", lst_lexer->data, type);

				lst_lexer = lst_lexer->next;
			}*/