/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:21:53 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/15 19:20:31 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_a_new_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	remove_next_line(char *buffer, int next)
{
	char	*after_line;
	int		i;

	if (next == (int)ft_strlen(buffer))
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		return ;
	}
	after_line = buffer + next;
	i = 0;
	if (after_line[i] == '\n')
		after_line += 1;
	while (after_line[i])
	{
		buffer[i] = after_line[i];
		i++;
	}
	ft_memset(buffer + i, 0, BUFFER_SIZE - i);
}

static char	*fill_line(char *line, char *buffer, int len)
{
	char	*back;
	int		i;
	int		j;

	if (is_a_new_line(buffer))
		len += 1;
	back = (char *)ft_calloc(len + 1, sizeof(char));
	if (!back)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		back[i] = line[i];
		i++;
	}
	free(line);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		back[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		back[i + j] = '\n';
	return (back);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			browsed;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	browsed = 1;
	line = NULL;
	while (browsed > 0)
	{
		if (buf[0] != '\0')
			line = fill_line(line, buf, find_next_line(buf) + ft_strlen(line));
		if (buf[0] == '\0')
		{
			browsed = read(fd, buf, BUFFER_SIZE);
			line = fill_line(line, buf, find_next_line(buf) + ft_strlen(line));
		}
		remove_next_line(buf, find_next_line(buf));
		if (is_a_new_line(line))
			return (line);
	}
	if (line)
		free(line);
	return (NULL);
}
