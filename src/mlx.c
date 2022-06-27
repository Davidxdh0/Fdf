/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:24:42 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/27 18:04:38 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	keypress(int keycode, t_data *data)
{
	keycode++;
		
	mlx_destroy_image(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	//free_arr(matrix);
	//clear window?
	return (0);
}

void	create_window(t_data *data)
{
	//printf("test %.0f ", (data->matrix[1][1].z));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Hello Fdf!");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
}

int draw(t_matrix **matrix, t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
		{
			//printf("%.0f ", (matrix[i][j].z));
			//draw_dots(0, j*20+500, (matrix[i][j].z + i)+i*10 + 500, data);
			
			if ((matrix[i][j].z) > 5)
				draw_dots(0, j*20+1000, i*20 + 500, data);
			else
				draw_dots(1, j*20+1000, i*20 + 500, data);
			
			// if (i + 1 < 11)
			// 	breshelper(j*30+400, (matrix[i][j].z+i)+i*20+400, j*30+401, (matrix[i+1][j].z+i)+i*20+400, data);
			// else
			// 	breshelper(j*30+400, (matrix[i][j].z+i)+i*20+400, j*30+401, (matrix[i][j].z+i)+i*20+400, data);
			
			
			//printf("reader x = %d, y = %d\n", frame->max_x, frame->max_y);
			j++;
		}
		printf("\n");
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}
