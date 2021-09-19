/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:38:15 by mleonars          #+#    #+#             */
/*   Updated: 2021/06/26 23:45:53 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strcat(char *dest, const char *src, size_t i)
{
	size_t	j;

	j = 0;
	if (!src)
		return ((char *)dest);
	if (!dest)
		return (NULL);
	while (src[j] != 0)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	tot_len;
	char	*out;

	if (!s2)
		return ((char *)s1);
	i = ft_strlen(s1);
	tot_len = i + ft_strlen(s2);
	out = malloc(sizeof(char) * (tot_len + 1));
	if (!out)
		return (NULL);
	*out = 0;
	ft_gnl_strcat(out, (char *)s1, 0);
	ft_gnl_strcat(out, (char *)s2, i);
	out[tot_len] = 0;
	free(s1);
	return (out);
}

int	ft_gnl_new_line(char *save)
{
	size_t	i;

	if (!save)
		return (-1);
	i = 0;
	while (save[i] != 0)
	{
		if (save[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}

int	ft_error_exit(char *save, char *buf)
{
	free(save);
	free(buf);
	return (-1);
}
