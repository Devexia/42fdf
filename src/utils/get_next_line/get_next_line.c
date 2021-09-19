/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:51:50 by mleonars          #+#    #+#             */
/*   Updated: 2021/06/26 23:45:52 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_get_save(char *save)
{
	char	*out;
	int		i;
	int		j;

	if (!save)
		return (0);
	i = 0;
	j = 0;
	while (save[i] != 0 && save[i] != '\n')
		i++;
	if (save[i] == 0)
	{
		free(save);
		return (0);
	}
	out = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!out)
		return (0);
	i++;
	while (save[i] != 0)
		out[j++] = save[i++];
	out[j] = 0;
	free(save);
	return (out);
}

char	*gnl_get_line(char *save)
{
	char	*out;
	int		i;

	i = 0;
	while (save[i] != '\n' && save[i] != 0)
		i++;
	out = malloc(sizeof(char) * i + 1);
	if (!out)
		return (NULL);
	out[i] = 0;
	while (--i >= 0)
		out[i] = save[i];
	return (out);
}

int	ft_readjoin(char **buf, char **save, int ret, int fd)
{
	while ((ft_gnl_new_line(*save) != 0) && (ret != 0))
	{
		ret = read(fd, (*buf), BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		(*buf)[ret] = 0;
		(*save) = ft_gnl_strjoin(*save, (*buf));
		if (!(*save))
			return (-1);
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			ret;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || !buf)
		return (ft_error_exit(save, buf));
	ret = 1;
	ret = ft_readjoin(&buf, &save, ret, fd);
	if (save == NULL)
		return (ft_error_exit(save, buf));
	free(buf);
	*line = gnl_get_line(save);
	if (!(*line))
		return (ft_error_exit(save, buf));
	save = gnl_get_save(save);
	if (ret != 0)
		return (1);
	if (save)
		free(save);
	return (0);
}
