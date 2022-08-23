/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 09:57:43 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/23 09:58:04 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(char **arg)
{
	int	i;

	i = 0;
	if (!arg)
		return ;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_y)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

void	free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free_map(data);
	exit(0);
}
