/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <meudier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:42:21 by meudier           #+#    #+#             */
/*   Updated: 2022/05/24 13:05:13 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static int	there_is_newline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

static char	*ft_get_line_and_str(char **str, char **line)
{
	int		i;
	int		len;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	if ((*str)[len] == '\n')
		len++;
	*line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len && (*str)[i])
	{
		(*line)[i] = (*str)[i];
		i++;
	}
	(*line)[i] = 0;
	i = 0;
	while ((*str)[len])
		(*str)[i++] = (*str)[len++];
	(*str)[i] = 0;
	return (*line);
}

static char	*no_leaks(char **str, char *buffer)
{
	char	*temp;

	if (buffer)
		free (buffer);
	if (*str && ft_strlen(*str))
	{
		temp = *str;
		*str = NULL;
		return (temp);
	}
	return (NULL);
}

int	get_str(int *rtr, int fd, char *buffer, char **str)
{
	char	*temp;

	*rtr = read(fd, buffer, BUFFER_SIZE);
	if (*rtr == -1)
		return (0);
	buffer[*rtr] = 0;
	if (!ft_strlen(buffer) && !*rtr && !there_is_newline(*str))
		return (0);
	temp = *str;
	*str = ft_strjoin(temp, buffer);
	free (temp);
	if (there_is_newline(*str))
		return (1);
	return (2);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str = NULL;
	int			rtr;
	char		*line;
	char		*temp;
	int			ret;

	rtr = BUFFER_SIZE;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (no_leaks(&str, buffer));
	while (rtr > 0)
	{
		ret = get_str(&rtr, fd, buffer, &str);
		if (!ret)
			return (no_leaks(&str, buffer));
		if (ret == 1)
			break ;
	}
	ft_get_line_and_str(&str, &line);
	if (!line)
		return (no_leaks(&str, buffer));
	free (buffer);
	return (line);
}

int main()
   {
   int     fd;
   char    *line1;
   char    *line2;
   char    *line3;
   char    *line4;
   char    *line5;

   	fd = open("./text", O_RDONLY);
   	line2 = get_next_line(fd);
   	line3 = get_next_line(fd);
	line4 = get_next_line(fd);
	line5 = get_next_line(fd);
	//line1 = get_next_line(fd);

	//printf("%s",line1);
	//free(line1);
	free(line2);
	free(line3);
	free(line4);
	free(line5);
	close (fd);
	
	return (0);
}