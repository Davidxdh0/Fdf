/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_util.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 12:10:32 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/26 12:38:33 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_dots(int x, int y, float temp, t_data *data)
{
	float	ix;
	float	iy;
	int		windowx;
	int		windowy;
	float	tempy;

	ix = x;
	iy = y;
	windowy = WINDOW_Y / ((data->max_x + data->max_y));
	windowx = WINDOW_X / (data->max_x + data->max_y);
	data->matrix[y][x].x = (ix + data->max_y) * windowx;
	data->matrix[y][x].y = iy * windowy;
	temp = data->matrix[y][x].x;
	tempy = data->matrix[y][x].y;
	data->matrix[y][x].x = (temp * cos(45)) - (tempy * sin(45));
	data->matrix[y][x].y = (tempy * cos(45)) + ((temp * sin(45)) / 2) \
							- data->matrix[y][x].z * 4;
	if (data->width > data->matrix[y][x].x)
		data->width = data->matrix[y][x].x;
	if (data->widtht < data->matrix[y][x].x)
		data->widtht = data->matrix[y][x].x;
	if (data->matrix[y][x].y < data->height)
		data->height = data->matrix[y][x].y;
	if (data->matrix[y][x].y > data->low)
		data->low = data->matrix[y][x].y;
}

void	connect_dots_util1(int x, int y, float m, t_data *data)
{
	data->x = x;
	data->y = y;
	data->m = m;
}

void	connect_dots_util2(float newy, float temp, t_data *data)
{
	while (data->newx <= data->matrix[data->y][data->x + 1].x)
	{
		newy = (data->m * (data->newx - data->matrix[data->y][data->x].x) \
				+ data->matrix[data->y][data->x].y);
		if (data->matrix[data->y][data->x].z > data->max_z / 2 && \
				data->matrix[data->y][data->x + 1].z > data->max_z / 2)
			my_mlx_pixel_put(data, data->newx, newy, 0xFF0000);
		else if (data->matrix[data->y][data->x + 1].z > data->max_z / 2)
			my_mlx_pixel_put(data, data->newx, newy, (0xffffff - \
				(data->newx - data->matrix[data->y][data->x].x) * temp));
		else if (data->matrix[data->y][data->x + 1].z < data->max_z \
				/ 2 && data->matrix[data->y][data->x].z > data->max_z / 2)
			my_mlx_pixel_put(data, data->newx, newy, (0xff0000) + \
				(data->newx - data->matrix[data->y][data->x].x) * temp);
		else
			my_mlx_pixel_put(data, data->newx, newy, 0xFFFFFF);
		if (data->max_x > 400)
			data->newx = data->newx + 0.002;
		else
			data->newx += 0.01;
	}
}

// else if (data->matrix[data->y + 1][data->x].z < data->max_z / 2 
// 		&& data->matrix[data->y][data->x].z > data->max_z / 2)
// 	my_mlx_pixel_put(data, data->newx, newy, (0xff0000) + 
// 		(data->newx - data->matrix[data->y][data->x].x) * temp);
void	connect_vert_util(int x, float newy, float temp, t_data *data)
{
	while (data->x < data->max_x)
	{
		x = data->x;
		data->newx = data->matrix[data->y][data->x].x;
		temp = 65535 / (data->matrix[data->y + 1][data->x].x - data->newx);
		data->m = (data->matrix[data->y + 1][x].y - data->matrix[data->y][x].y) \
		/ (data->matrix[data->y + 1][x].x - data->matrix[data->y][x].x);
		while (data->newx >= data->matrix[data->y + 1][data->x].x)
		{
			newy = (data->m * (data->newx - data->matrix[data->y][x].x) + \
				data->matrix[data->y][x].y);
			if (data->matrix[data->y][data->x].z > data->max_z / 2 && \
					data->matrix[data->y + 1][data->x].z > data->max_z / 2)
				my_mlx_pixel_put(data, data->newx, newy, 0xFF0000);
			else if (data->matrix[data->y + 1][data->x].z > data->max_z / 2)
				my_mlx_pixel_put(data, data->newx, newy, (0xffffff - \
				(data->newx - data->matrix[data->y][data->x].x) * temp));
			else
				my_mlx_pixel_put(data, data->newx, newy, 0xFFFFFF);
			data->newx = data->newx - 0.003;
		}
		data->x++;
	}
}

void	max(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->low = 200;
	data->widtht = 200;
	while (i < data->max_y)
	{
		j = 0;
		while (j < data->max_x)
		{
			if (data->widtht < data->matrix[i][j].x)
				data->widtht = data->matrix[i][j].x + fabs(data->width) + 50;
			if (data->low < data->matrix[i][j].y)
				data->low = data->matrix[i][j].y + fabs(data->height) + 50;
			j++;
		}
		i++;
	}
}
