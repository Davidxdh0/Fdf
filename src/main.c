/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/05 08:09:44 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/27 15:37:55 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	**reader(int argc, char *file, t_data *data)
{
	//t_matrix **matrix;
	int fd;
	int i;

	i = 0;
	if (argc == 2)
	{
		if (!(fd = open(file, O_RDONLY)))
		{	
			printf("reader, fd onder 0 + close fd");
			exit(0);
		}
		data->max_x = countx(file);
		data->max_y = county(file);
		data->matrix = fill_matrix(data->max_x, data->max_y, file);
	}
	else
	{	
		printf("reader, argc != 2");
		exit(1);
	}
	close(fd);
	return (data->matrix);
}

int	main(int argc, char **argv)
{
	t_matrix	**matrix;
	t_data		data;
	
	matrix = reader(argc, argv[1], &data); //parser
	//printf("x=%d, y=%d", data.max_x, data.max_y );
	create_window(&data);
	draw(matrix, &data);
	//stuur matrix met data mee.
	mlx_hook(data.win, 2, 1L<<0, keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}
