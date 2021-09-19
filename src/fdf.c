/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:39:42 by mleonars          #+#    #+#             */
/*   Updated: 2021/09/12 05:39:45 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "get_next_line.h"

void	key_hook(int keycode)
{
	printf("|%d\n|", keycode);
}

void	ft_free_tab(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	if (split)
		free(split);
}

void	scale_map(t_map *map)
{
	float	ratio_v;
	float	ratio_h;

	ratio_v = (float)HEIGHT
		/ ((map->point_arr[map->highest].x
				+ map->point_arr[map->highest].y
				- map->point_arr[map->highest].z / 5)
			- (map->point_arr[map->lowest].x
				+ map->point_arr[map->lowest].y - 16
				- map->point_arr[map->lowest].z / 5));
	ratio_h = ratio_h_calc(map);
	if (ratio_v >= ratio_h)
		map->ratio = ratio_h;
	else
		map->ratio = ratio_v;
	map->shift_left = ((map->point_arr[0].x - map->point_arr[0].y) * 2
			- (map->point_arr[map->height * map->width - map->width].x
				- map->point_arr[map->height * map->width - map->width].y)
			* 2 + 8) * ratio_h;
	map->shift_up = 8 * ratio_v;
}

void	find_extremities(t_map *map)
{
	int	i;
	int	highest;
	int	lowest;

	i = -1;
	lowest = lowest_calc(map);
	highest = (map->point_arr[0].x + map->point_arr[0].y
			- map->point_arr[0].z / 5);
	while (++i < (map->height * map->width))
	{
		if ((map->point_arr[i].x + map->point_arr[i].y - \
		map->point_arr[i].z / 5) > highest)
		{
			highest = (map->point_arr[i].x + map->point_arr[i].y
					- map->point_arr[i].z / 5);
			map->highest = i;
		}
		if ((map->point_arr[i].x + map->point_arr[i].y - \
		map->point_arr[i].z / 5) <= lowest)
		{
			lowest = (map->point_arr[i].x
					+ map->point_arr[i].y - map->point_arr[i].z / 5);
			map->lowest = i;
		}
	}
}

int	main(int ac, char **av)
{
	t_map	map;
	char	**tab;
	char	**nb;

	init_structs(&map);
	if (ac <= 1)
		return (printf("plz input .fdf file\n"));
	tab = parse_map(av, &map);
	get_size(tab, &map);
	nb = NULL;
	map.point_arr = malloc(sizeof(t_point) * map.height * map.width);
	if (!map.point_arr)
		return (-1);
	char_tab_to_point_arr(&map, tab, nb);
	ft_free_tab(tab);
	find_extremities(&map);
	scale_map(&map);
	mlx_stuff(&map);
	return (0);
}
