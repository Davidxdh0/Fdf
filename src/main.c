/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/05 08:09:44 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/16 18:16:19 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	**reader(int argc, char *file)
{
	t_frame *frame;
	t_matrix **matrix;
	int fd;
	int i;

	i = 0;
	if (argc == 2)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{	
			printf("reader, fd onder 0 + close fd");
			exit(1);
		}
		frame = list_new();
		frame->max_x = countx(file);
		frame->max_y = county(file);
		matrix = fill_matrix(frame->max_x, frame->max_y, file);
		
		//printf("reader x = %d, y = %d\n", frame->max_x, frame->max_y);
	}
	else
	{	
		printf("reader, argc != 2");
		exit(1);
	}
	return (matrix);
}

int	main(int argc, char **argv)
{
	t_matrix **matrix;
	
	matrix = reader(argc, argv[1]);
	create_window(matrix);
	return (0);
}
