/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:24:42 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/17 20:24:56 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	closes(int keycode, t_data *vars)
{
	keycode++;	
	mlx_destroy_image(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	free(vars->win);
	free(vars);
	return (0);
}

int	create_window(t_matrix **matrix)
{
	t_data	img;
	t_data 	vars;
	
	int i;
	int j;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 11)
		{
			//void DDA(int x, int y, int x1, int y1, int *img)
			//printf("%.0f ", matrix[i][j].z);
			DDA(j*20, (matrix[i][j].z + i)*20, (j+1)*20, (matrix[i][j].z + i + 1)*20, img);
			DDA(j*20, (matrix[i][j].z + i)*20, (j+1)*20, (matrix[i][j].z + i + 1)*20, img);
			//DDA(0, 0, 0, 0, img);
			//my_mlx_pixel_put(&img, i+500, j+500, 0x00FF0000+i*300);
			//my_mlx_pixel_put(img, x, y, 0x00FF0000);
			
			//printf("reader x = %d, y = %d\n", frame->max_x, frame->max_y);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, closes, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
