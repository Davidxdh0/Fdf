/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:24:42 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/16 18:15:55 by dyeboa        ########   odam.nl         */
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
	matrix[i][0].z = 1;
	while (i < 3)
	{
		j = 0;
		while (j < 11)
		{
			DDA(matrix[i][j].z, matrix[i][j].z, matrix[i][j+1].z, matrix[i+1][j].z, img.img);
			//my_mlx_pixel_put(&img, i, j, 0x00FF0000+i*300);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, closes, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
