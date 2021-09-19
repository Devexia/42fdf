/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:59:41 by mleonars          #+#    #+#             */
/*   Updated: 2021/09/19 03:04:05 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (src == 0)
	{
		dst = 0;
		return (0);
	}
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (src[a] && a < size - 1)
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (i);
}
