/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:37:46 by meudier           #+#    #+#             */
/*   Updated: 2022/06/01 16:37:17 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
int     ft_printf(const char *str, ...);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *s);
int 	free_tab(char **tab);
int 	free_tab_int(int **tab, int size);
int     create_process(int num_of_process, int **pipes, char **av, char **env);
void    close_all_fd(int **pipes, int num_of_process, int in_file, int out_file);
int     get_file_fd(int *in_file, int *out_file, char **av, int ac);
int     **get_pipes(int num_of_process);
void    dup_fd(int i, int num_of_process, int **pipes, int in_file, int out_file);

#endif
