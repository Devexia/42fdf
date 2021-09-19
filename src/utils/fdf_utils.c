/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 04:19:19 by mleonars          #+#    #+#             */
/*   Updated: 2021/08/22 04:49:03 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_hexa_base(char *str)
{
	int		res;
	int		i;
	char	*base;
	int		j;

	base = "0123456789abcdef";
	res = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		res = res * 16 + j;
		i++;
	}
	return (res);
}

void	init_structs(t_map *map)
{
	map->width = 1;
	map->height = 0;
	map->ratio = 0;
	map->shift_left = 0;
	map->shift_up = 0;
	map->lowest = 0;
	map->highest = 0;
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length) + \
	(x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_win(int keycode, t_vars *vars, t_map map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_exit(&map, NULL, 0);
	}
	return (0);
}

void	ft_exit(t_map *map, char *display, int status)
{
	int	i;

	i = 0;
	if (display)
		printf("%s", display);
	if (map->point_arr)	
		free(map->point_arr);
	(void)map;
	if (status == -1)
		exit(-1);
	else
		exit(0);
}
