/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:07:23 by agondard          #+#    #+#             */
/*   Updated: 2021/12/06 21:46:43 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	there_is_n(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

int	lenn(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *cpy)
{
	cpy = (char *)malloc(1);
	if (!cpy)
		return (NULL);
	*cpy = 0;
	return (cpy);
}

char	*strjoin(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*ret;

	if (!buffer)
		return (NULL);
	i = lenn(buffer);
	if (buffer[i] == '\n')
		++i;
	i += lenn(line);
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
