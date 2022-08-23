/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:24:42 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/23 13:10:14 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == 53)
		free_mlx(data);
	return (0);
}

void	create_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_X, WINDOW_Y, "fdf");
	data->img = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
				&data->line_length, &data->endian);
}
