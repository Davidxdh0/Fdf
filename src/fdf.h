/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 12:46:43 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/26 17:48:43 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_X		1920
# define WINDOW_Y		1080
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_matrix
{
	float	x;
	float	y;
	float	z;
	int		colour;
}			t_matrix;

typedef struct s_data {
	void		*img;
	void		*mlx;
	void		*win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			max_x;
	int			max_y;
	int			x;
	int			y;
	int			flag;
	float		m;
	float		newx;
	float		max_z;
	float		min_z;
	float		height;
	float		low;
	float		width;
	float		widtht;
	t_matrix	**matrix;
}				t_data;

//parse_util.C
void		max_numbers(int i, char *file, t_data *data);
void		z_values(t_data *data);
void		reader(int argc, char *file, t_data *data);
void		max(t_data *data);

//mlx.C
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			keypress(int keycode, t_data *vars);
int			keypressx(t_data *data);
void		create_window(t_data *data);

//fill.c
t_matrix	**fill_matrix(int x, int y, char *file);
void		height(int x, int y, char *file, t_matrix **matrix);
void		printlist(t_matrix **matrix, int x, int y);

//draw.c
void		center_dots(t_data *data);
void		connect_dots(int x, int y, float newx, t_data *data);
void		connect_vert(int x, t_data *data);
int			draws(t_data *data);
int			draw(t_data *data);

//draw_util.c
void		draw_dots(int x, int y, float temp, t_data *data);
void		connect_dots_util1(int x, int y, float m, t_data *data);
void		connect_dots_util2(float newy, float temp, t_data *data);
void		connect_vert_util(int x, float newy, float temp, t_data *data);

//exit.c
void		exitmsg(void);
void		free_arr(char **arg);
void		free_mlx(t_data *data);
void		free_map(t_data *data);

#endif
