/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 03:13:30 by mleonars          #+#    #+#             */
/*   Updated: 2021/09/19 03:13:31 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

int	get_next_size(int fd, char **av)
{
	char	*buf;
	int		ret;
	int		i;
	int		nlcount;

	ret = 1;
	fd = open(av[1], O_RDONLY);
	i = 0;
	nlcount = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (1);
	while (ret != 0)
	{
		ret = read(fd, &(*buf), BUFFER_SIZE);
		while (buf[i])
		{
			i++;
			if (buf[i] == '\n')
				nlcount++;
		}
		i = 0;
	}
	close(fd);
	return (nlcount);
}
