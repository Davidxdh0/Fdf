/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/05 08:09:44 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/22 16:23:25 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void test(void)
{
    system("leaks -q fdf");
}
int	main(int argc, char **argv)
{
	atexit(test);
	t_data		data;
	clock_t t;
	double time_taken;
	t = clock();
	reader(argc, argv[1], &data); //parser
	t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
   	printf("read %f seconds \n", time_taken);
	
	
	t = clock();
	create_window(&data);
   	t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("create %f seconds \n", time_taken);
	//printlist(data.matrix, data.max_x, data.max_y);
	t = clock();
	draw(&data);
   	t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("draw %f seconds \n", time_taken);
	
	//printlist(data.matrix, data.max_x, data.max_y);
	t = clock();
	mlx_hook(data.win, 2, 1L<<0, keypress, &data);
	mlx_loop(data.mlx);
   	t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("mlx %f seconds \n", time_taken);
	
	return (0);
}