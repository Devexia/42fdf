#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef union u_type {
	int				BGRT;

	struct {
		unsigned char	B;
		unsigned char	G;
		unsigned char	R;
	};
}				t_union;

typedef	struct	s_point {
	int		x;
	int		y;
	int		z;
	t_union	color;
}				t_point;

typedef struct s_pxl
{
	float	x;
	float	y;
}			t_pxl;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map
{
	int 	width;
	int 	height;
	t_point *point_arr;
	float 	ratio;
	int		highest;
	int		lowest;
	float	shift_left;
	float	shift_up;
	t_pxl	*pxl;
}				t_map;

#endif
