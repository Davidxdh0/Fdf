/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 12:46:43 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/16 18:13:05 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include<math.h>

typedef struct s_frame
{
	int max_x;
	int max_y;
	int max_z;
	int min_z;
}	t_frame;

typedef struct s_matrix
{
	float x;
	float y;
	float z;
}	t_matrix;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


//main.c
t_matrix	**reader(int argc,char *file);
int			main(int argc, char **argv);

//parse_util.C
int 		countx(char *file);
int 		county(char *file);
int			height(int x, int y, char *file);

//mlx.C
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			closes(int keycode, t_data *vars);
int			create_window();

//lists.c
t_frame		*list_new(void);
t_matrix	**fill_matrix(int x, int y, char *file);
void		printlist(t_matrix **matrix, int x, int y);

//draw.c
void DDA	(int x, int y, int x1, int y1, char *img);

