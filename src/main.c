/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/05 08:09:44 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/23 09:54:46 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void test(void)
// {
// 	system("leaks -q fdf");
// }
//atexit(test);
int	main(int argc, char **argv)
{
	t_data	data;

	reader(argc, argv[1], &data);
	create_window(&data);
	draw(&data);
	mlx_hook(data.win, 2, 1L << 0, keypress, &data);
	mlx_loop(data.mlx);
	exit(0);
	return (0);
}
