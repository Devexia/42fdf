/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:39:29 by mleonars          #+#    #+#             */
/*   Updated: 2021/09/17 11:43:27 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ratio_h_calc(t_map *map)
{
	float	ratio_h;

	ratio_h = (float)WIDTH
		/ ((map->point_arr[map->width - 1].x
				- map->point_arr[map->width - 1].y) * 2
			- (map->point_arr[(map->width * map->height)
				- map->width].x
				- map->point_arr[(map->width * map->height) - map->width].y - 8)
			 * 2);
	return (ratio_h);
}

float	lowest_calc(t_map *map)
{
	float	lowest;

	lowest = (map->point_arr[(map->height * map->width) - 1].x
			+ map->point_arr[(map->height * map->width) - 1].y
			- map->point_arr[(map->height * map->width) - 1].z / 5);
	return (lowest);
}
