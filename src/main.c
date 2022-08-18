/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/05 08:09:44 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/18 12:47:51 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data		data;
	
	reader(argc, argv[1], &data); //parser
	create_window(&data);
	draw(&data);
	//printlist(data.matrix, data.max_x, data.max_y);
	mlx_hook(data.win, 2, 1L<<0, keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}
//printf("x=%d, y=%d", data.max_x, data.max_y );