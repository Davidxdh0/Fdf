/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 12:46:43 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/18 18:04:53 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#define WINDOW_X		1920
#define WINDOW_Y		1080
typedef struct s_matrix
{
	float 	x;
	float 	y;
	float 	z;
	int 	colour;
}			t_matrix;

typedef struct	s_data {
	void		*img;
	void		*mlx;
	void		*win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int 		max_x;
	int 		max_y;
	float 		max_z;
	float		min_z;
	t_matrix	**matrix;
}				t_data;

//main.c
void		reader(int argc, char *file, t_data *data);
int			main(int argc, char **argv);

//parse_util.C
void		max_numbers(char *file, t_data *data);
int 		countx(char *file);
int 		county(char *file);

//mlx.C
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			keypress(int keycode, t_data *vars);
void		create_window(t_data *data);


//fill.c
t_matrix	**fill_matrix(int x, int y, char *file);
int			height(int x, int y, char *file);
void		printlist(t_matrix **matrix, int x, int y);
int			colour(int y, int x, char *file);

//draw.c
void 	DDA	(int x, int y, int x1, int y1, t_data *data);
void	draw_dots(int x, int y, t_data *data);
void 	breshelper(t_data *data);
void 	bresehamline(int x1, int y1, int x2, int y2, int dx, int dy, int decide, t_data *data);
void 	draw_ugly_line(t_data *data);
void 	connect_dots(t_data *data);
void 	connect_vert(t_data *data);
void 	connect_new_dots(int x, float tempnewy, float newy, int colour, t_data *data);
int 	colourgradient(int x, int y, t_data *data);
int 	draws(t_data *data);
int 	draw(t_data *data);

//exit.c
void	free_arr(char **arg);
void	free_mlx(t_data *data);
void	free_map(t_data *data);