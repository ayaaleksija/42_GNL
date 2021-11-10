/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:27:17 by agondard          #+#    #+#             */
/*   Updated: 2021/11/10 13:32:46 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>


char	*get_next_line(int fd);
int		there_is_n(char *c);
char	*ft_strdup(char *src);
int		lenn(char *str);
char	*rspecial_function(char *line, char *buffer);
char *clean_buffer(char *buffer, char *line);

# endif /* GET_NEXT_LINE_H */
