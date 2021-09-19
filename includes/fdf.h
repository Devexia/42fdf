#ifndef FDF_H
#define FDF_H

#include <math.h>
#include <unistd.h>
#include "mlx.h"
#include "structure.h"
#include "libft.h"
#include "get_next_line.h"

typedef	enum	e_scale
{
	HEIGHT = 1000,
	WIDTH = 1000,
}				t_scale;

//int	get_next_size(int fd, char **av);
char	**parse_map(char **av, t_map *map);
int		get_next_line(int fd, char **line);
void    draw_line(t_data *data, t_pxl first, t_pxl second, int color);
void	ft_put_pixel(t_data *data, int x, int y, int color);
void	char_tab_to_point_arr(t_map *map, char **tab, char **nb);
int		draw_wireframe(t_data *data, t_map *map);
void	get_size(char **tab, t_map *map);
void	init_structs(t_map *map);
int		ft_hexa_base(char *str);
void	calc_pxl(t_map *map);
void	ft_put_pixel(t_data *data, int x, int y, int color);
int		mlx_stuff(t_map *map);
void	ft_exit(t_map *map, char *display, int status);
int		close_win(int keycode, t_vars *vars, t_map map);
void	ft_free_tab(char **split);
float	ratio_h_calc(t_map *map);
float	lowest_calc(t_map *map);

# endif
