/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:38:25 by mleonars          #+#    #+#             */
/*   Updated: 2021/06/27 02:07:21 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFFER_SIZE 42

char	*ft_gnl_strcat(char *dest, const char *src, size_t i);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		ft_gnl_new_line(char *save);
int		ft_error_exit(char *save, char *buf);
int		get_next_line(int fd, char **line);
int		get_next_size(int fd, char **av);

#endif
