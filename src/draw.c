/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:47:36 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/26 17:38:29 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_dots(t_data *data)
{
	int	i;
	int	j;	

	i = 0;
	while (i < data->max_y)
	{
		j = 0;
		while (j < data->max_x)
		{
			if (data->width < 0)
				data->matrix[i][j].x += -1 * data->width + 10;
			if (data->widtht > 1900)
				data->matrix[i][j].x /= 2;
			if (data->height < 0)
				data->matrix[i][j].y += data->height * -1;
			if (data->low > 1000 || data->max_z > 30)
				data->matrix[i][j].y /= (data->low / 1000);
			if (data->max_x == 200 || data->max_z > 30)
				data->matrix[i][j].y /= 1.5;
			j++;
		}
		i++;
	}
}

void	connect_dots(int x, int y, float newx, t_data *data)
{
	float	m;
	float	newy;
	float	temp;

	m = 1;
	y = 0;
	newx = 0;
	newy = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x - 1)
		{
			newx = data->matrix[y][x].x;
			temp = data->matrix[y][x + 1].x - newx;
			temp = 65535 / temp;
			m = (data->matrix[y][x + 1].y - data->matrix[y][x].y) / \
				(data->matrix[y][x + 1].x - data->matrix[y][x].x);
			data->newx = newx;
			connect_dots_util1(x, y, m, data);
			connect_dots_util2(newy, temp, data);
			x++;
		}
		y++;
	}
}

void	connect_vert(int x, t_data *data)
{
	int		y;
	float	m;
	float	newx;
	float	newy;
	float	temp;

	m = 1;
	y = 0;
	newx = 0;
	newy = 0;
	temp = 0;
	while (y < data->max_y - 1)
	{
		x = 0;
		data->newx = newx;
		connect_dots_util1(x, y, m, data);
		connect_vert_util(x, newy, temp, data);
		y++;
	}
}

/*
Bereken vanaf waar ie getekend moet worden om lekker groot in beeld te komen
Teken lijnen tussen punten met kleursverschil in 5 stappen (z waarde high en low)
*/
int	draws(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->width = 1;
	data->widtht = 1900;
	data->height = 1;
	data->low = 1000;
	while (i < data->max_y)
	{
		j = 0;
		while (j < data->max_x - data->flag)
		{
			if (((data->max_z > -15 && data->max_z < 15)) && (data->max_x < 50 \
				&& data->max_y < 50) && data->max_y != 11)
				data->matrix[i][j].z *= 4;
			draw_dots(j, i, data->matrix[i][j].x, data);
			j++;
		}
		i++;
	}
	return (0);
}

int	draw(t_data *data)
{
	int		x;
	float	y;

	x = 0;
	y = 0;
	draws(data);
	center_dots(data);
	max(data);
	create_window(data);
	connect_dots(x, x, y, data);
	connect_vert(x, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}
