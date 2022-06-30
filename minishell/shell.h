/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxenceeudier <maxenceeudier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:32:02 by meudier           #+#    #+#             */
/*   Updated: 2022/06/29 18:21:18 by maxenceeudi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum type
{
    PIPE,
    REDIR_OUT,
    REDIR_IN,
    REDIR_OUT_APPEND,
    HERDOC,
    WRD
};

typedef struct s_lexer
{
    char            *data;
    int             type;
    struct s_lexer  *prev;
    struct s_lexer  *next;
}   t_lexer;

typedef struct s_in
{
    int stdin;
    struct s_in *next;
}   t_in;

typedef struct s_pipe_info
{
    int                 in;
    int                 out;
    int                 **pipes;
    int                 num_of_process;
    struct s_pipe_info *next;
}   t_pipe_info;

typedef struct s_parser
{
    char            *cmd;
    char            **arg;
    t_in             *stdin;
    int             stdout;
    struct s_parser  *prev;
    struct s_parser  *next;
}   t_parser;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int     ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split_lexer(char const *s);
int	    **get_pipes(t_lexer *lexer, int *num_of_process);

void	close_std(t_parser *parser);
void	close_pipes(t_pipe_info *pipe_info);

t_lexer	*lexer(char *line);
int	    get_num_of_arg(t_lexer *lexer);
void	push_lexer(t_lexer **lst, char *word, int TYPE);
void	lst_clear_lexer(t_lexer *lexer);

void	push_in(t_in **stdin, int data);
void	init_parser(t_parser *new);
void	push_parser(t_parser **parser, t_lexer **lexer, t_pipe_info *pipe_info);
t_parser	*parser(t_lexer *lexer, t_pipe_info *pipe_info);
void	lst_clear_parser(t_parser *parser);

int get_num_of_process(t_lexer *lexer);
int	**get_pipes(t_lexer *lexer, int *num_of_process);
int	is_not_a_pipe(int fd, int **pipes, int num_of_process);

char	**clear_tab(char **tab);
void	*ft_calloc(size_t count, size_t size);

char	*cpy(const char *src);
#endif
