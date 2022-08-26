/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/05 08:09:44 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/26 17:46:22 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
	{
		write(1, "Usage : ./42fdf <filename>\n", 28);
		exit(0);
	}
	reader(argc, argv[1], &data);
	draw(&data);
	mlx_hook(data.win, 2, 1L << 0, keypress, &data);
	mlx_hook(data.win, 17, 0, keypressx, &data);
	mlx_loop(data.mlx);
	exit(0);
	return (0);
}
