/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:04:32 by agondard          #+#    #+#             */
/*   Updated: 2021/12/06 21:54:39 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_buffer(char *buffer, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = lenn(buffer);
	if (buffer[j] == '\n')
		++j;
	while (buffer[j])
	{
		buffer[i] = buffer[j];
		++i;
		++j;
	}
	while (buffer[i])
	{
		buffer[i] = 0;
		++i;
	}
	return (line);
}

char	*free_line(char *line)
{
	if (!line)
		return (NULL);
	free (line);
	line = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*ret;
	int			b;
	static char	buffer[1024][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || read(fd, buffer[fd], 0) == -1)
		return (NULL);
	ret = ft_strdup("");
	ret = strjoin(ret, buffer[fd]);
	b = 1;
	while (b > 0 && !there_is_n(buffer[fd]))
	{
		b = read(fd, buffer[fd], BUFFER_SIZE);
		if (b == -1)
			return (free_line(ret));
		else if (b)
		{
			buffer[fd][b] = '\0';
			ret = strjoin(ret, buffer[fd]);
		}
		else if (b == 0 && buffer[fd][0] != 0)
			return (clean_buffer(buffer[fd], ret));
		else
			return (free_line(ret));
	}
	return (clean_buffer(buffer[fd], ret));
}
