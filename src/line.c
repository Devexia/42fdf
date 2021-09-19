/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:40:29 by mleonars          #+#    #+#             */
/*   Updated: 2021/09/12 05:40:30 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *data, t_pxl a, t_pxl b, int color)
{
	float	t;
	float	offset;
	t_pxl	ab;

	t = 0;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	offset = 1 / hypotf(ab.x, ab.y);
	while (t <= 1)
	{
		if (0 <= t * ab.x + a.x && t * ab.x + a.x < WIDTH
			&& 0 <= t * ab.y + a.y && t * ab.y + a.y < HEIGHT)
			ft_put_pixel(data, t * ab.x + a.x, t * ab.y + a.y, color);
		t += offset;
	}
}

void	calc_pxl(t_map *map)
{
	int	i;

	i = 0;
	map->pxl = malloc(sizeof(t_pxl) * (map->width * map->height));
	while (i < (map->width * map->height))
	{
		map->pxl[i].x = (map->point_arr[i].x
				- map->point_arr[i].y) * 2 * map->ratio
			+ map->shift_left;
		map->pxl[i].y = (map->point_arr[i].x
				+ map->point_arr[i].y - map->point_arr[i].z / 5)
			* map->ratio + map->shift_up;
		i++;
	}
}

int	draw_wireframe(t_data *data, t_map *map)
{
	int	i;

	calc_pxl(map);
	i = 0;
	while (i < (map->height * map->width))
	{
		if (i < (map->height * map->width) - map->width)
			draw_line(data, map->pxl[i], map->pxl[i + map->width],
				map->point_arr[i].color.BGRT);
		if ((i + 1) % map->width != 0)
			draw_line(data, map->pxl[i], map->pxl[i + 1],
				map->point_arr[i].color.BGRT);
		i++;
	}
	return (0);
}

int	mlx_stuff(t_map *map)
{	
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "screen");
	mlx_hook(vars.win, 2, 1L, close_win, &vars);
	mlx_hook(vars.win, 17, 0L, close_win, &vars);
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_wireframe(&img, map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
