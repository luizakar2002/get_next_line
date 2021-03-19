/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:18:05 by lukarape          #+#    #+#             */
/*   Updated: 2021/02/08 20:31:56 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*memory;
	int			get;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	get = 1;
	while ((get = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[get] = '\0';
		printf("%d\n", get);
		memory = ft_strjoin(memory, buf);
		if (ft_strendl(memory))
			break ;
	}
	free(buf);
	if (get < 0)
		return (-1);
	*line = ft_getline(memory);
	memory = ft_clearmemory(memory);
	if (get == 0 && !memory)
		return (0);
	return (1);
}
