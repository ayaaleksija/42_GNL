/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:27:05 by agondard          #+#    #+#             */
/*   Updated: 2021/11/09 17:59:13 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		there_is_n(char *c)
{
	int i;

	i = -1;
	while (c[++i])
	{
		if (c[i] == '\n')
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			b;

	ret = ft_strdup("");
	ret = rspecial_function(ret, buffer);
	while (!there_is_n(buffer))
	{
		b = read(fd, buffer, BUFFER_SIZE);

		if (b == -1)
			return (NULL);
		else if (b == 0)
		{
			return (NULL);
		}
		ret = rspecial_function(ret, buffer);
	}
	return (ret);
}

int	main(void)
{
	char	*txt;
	int		fd;

	fd = open("tamere.txt", O_RDONLY);
	while(fd)
	{
		txt = get_next_line(fd);
		printf("%s", txt);
		if (txt == NULL)
			break;
		free(txt);
	}
	close(fd);
	return (0);
}
