/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:32:02 by meudier           #+#    #+#             */
/*   Updated: 2022/06/28 13:05:53 by meudier          ###   ########.fr       */
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

typedef struct s_parser
{
    char            *cmd;
    char            **arg;
    int             stdin;
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

#endif
