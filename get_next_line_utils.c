/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:33:19 by agondard          #+#    #+#             */
/*   Updated: 2021/11/09 19:03:36 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		lenn(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		++i;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		size;

	size = lenn(src);
	cpy = (char *)malloc(sizeof (char) * (size + 1));
	if (!cpy)
		return (NULL);
	size = 0;
	while (src[size])
	{
		cpy[size] = src[size];
		size++;
	}
	cpy[size] = '\0';
	return (cpy);
}

char	*rspecial_function(char *line, char *buffer)
{
	int		i;
	int 	j;
	char	*ret;

	if (buffer == NULL)
		return (NULL);
	i = lenn(buffer) + lenn(line);
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	j = -1;
	while (line[++j])
		ret[j] = line[j];
	free(line);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		ret[j++] = buffer[i++];
	if (buffer[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*clean_buffer(char *buffer, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = lenn(buffer);
	if (buffer[j] == '\n')
		++j;
	while (buffer[i])
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
