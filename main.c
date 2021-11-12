/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:43:25 by agondard          #+#    #+#             */
/*   Updated: 2021/11/09 19:02:10 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void f(void)
{
    system("leaks a.out");
}

int main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("tamere.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf(">>> line : |%s| <<<\n", line);
		free(line);
	}
	line = get_next_line(fd);
	printf(">>> line : |%s| <<<\n", line);
	free(line);
	atexit(f);
	close (fd);
	return (0);
}
