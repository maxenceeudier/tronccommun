/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:37:46 by meudier           #+#    #+#             */
/*   Updated: 2022/06/02 16:45:06 by meudier          ###   ########.fr       */
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

typedef struct s_fds
{
	int	in_file;
	int	out_file;
	int	**pipes;
}	t_fds;

typedef struct s_exec
{
	char	**arg;
	char	*cmd_path;
	char	**av;
	char	**env;
	char	**cmd;
	char	**path;
	int		num_of_process;
}	t_exec;

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		free_tab(char **tab);
int		free_tab_int(int **tab, int size);
int		create_process(t_fds *fd, t_exec *vars);
void	close_all_fd(int num_of_process, t_fds *fd);
int		get_file_fd(t_fds *files, char **av, int ac);
int		**get_pipes(int num_of_process);
int		dup_fd(int i, int num_of_process, t_fds *fd);
int		get_path_and_arg(t_exec *vars, int i);
int		init_fd_pid(int num_of_process, t_fds *fd, t_exec *vars, int **pids);

#endif
