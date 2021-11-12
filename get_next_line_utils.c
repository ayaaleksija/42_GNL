/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:07:23 by agondard          #+#    #+#             */
/*   Updated: 2021/11/12 14:05:16 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		there_is_n(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		lenn(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	size_t	size;

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
	cpy[size] = 0;
	return (cpy);
}

char	*strjoin(char *line, char *buffer)
{
	int		i;
	int 	j;
	char	*ret;

	if (!buffer)
		return (NULL);
	i = lenn(buffer) + lenn(line);
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	j = -1;
	while (line[++j])
		ret[j] = line[j];
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		ret[j++] = buffer[i++];
	if (buffer[i] == '\n')
		ret[j++] = '\n';
	ret[j] = '\0';
	free(line);
	return (ret);
}
