/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:40:17 by mleonars          #+#    #+#             */
/*   Updated: 2021/09/12 05:40:18 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

char	**parse_map(char **av, t_map *map)
{	
	int		i;
	char	*line;
	char	**tab;
	int		fd;

	fd = 0;
	map->height = get_next_size(fd, av) - 1;
	tab = (char **)malloc(sizeof(char *) * map->height + 1);
	if (!tab)
		ft_exit(map, "Malloc error\n", -1);
	i = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_exit(map, "Open error", -1);
	while (get_next_line(fd, &line) == 1)
	{
		tab[i] = ft_strdup(line);
		free(line);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

void	get_color(t_map *map, char *nb, int arr_index)
{
	int	i;

	i = 0;
	while (nb[i] && nb[i] != ',')
		i++;
	if (nb[i] == ',')
	{
		i += 3;
		map->point_arr[arr_index].color.BGRT = ft_hexa_base(&nb[i]);
	}
	else
		map->point_arr[arr_index].color.BGRT = 16777215;
}

void	fill_points(char **nb, t_map *map, int y)
{
	int	i;
	int	j;
	int	arr_index;

	i = 0;
	j = 0;
	while (nb[i])
	{
		arr_index = y * map->width + i;
		map->point_arr[arr_index].z = ft_atoi(nb[i]);
		get_color(map, nb[i], arr_index);
		map->point_arr[arr_index].x = i;
		map->point_arr[arr_index].y = y;
		i++;
	}
}

void	char_tab_to_point_arr(t_map *map, char **tab, char **nb)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		nb = ft_split(tab[i], ' ');
		if (!nb)
			ft_exit(map, "Malloc error\n", -1);
		fill_points(nb, map, i);
		ft_free_tab(nb);
		i++;
	}
}

void	get_size(char **tab, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->height = 0;
	while (tab[i][++j])
	{
		if (tab[i][j] == ' ' && tab[i][j + 1] != '\0')
		{
			map->width++;
			while (tab[i][j] == ' ' && tab[i][j + 1] != '\0')
				j++;
		}
	}
	while (tab[i])
	{
		map->height++;
		i++;
	}
}
