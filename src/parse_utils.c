/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 12:46:16 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/22 16:06:01 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void max_numbers(char *file, t_data *data)
{
	int fd;
	int ymax;
	char *read_code;
	char **line;
	int i;

	i = 0;
	ymax = 0;
	fd = open(file, O_RDONLY);
	read_code = get_next_line(fd);
	line = ft_split(read_code, ' ');
	while(line[i])
		i++;

	while (read_code != 0 && ymax++ >= -200)
	{
		read_code = get_next_line(fd);
	}
	data->max_x = i;
	data->max_y = ymax;
	free_arr(line);
	free(read_code);
	close(fd);
}

void z_values(t_data *data)
{
	int x;
	int y;
	
	x = 1;
	data->max_z = 0;
	data->min_z = 0;
	while (x < data->max_y)
	{
		y = 1;
		while(y < data->max_x)
		{
			if (data->max_z < data->matrix[x][y].z)
				data->max_z = data->matrix[x][y].z;
			if (data->min_z > data->matrix[x][y].z)
				data->min_z = data->matrix[x][y].z;
			y++;
		}
		x++;
	}
	//printf("%d, %d", data->min_z, data->max_z);
}

void	reader(int argc, char *file, t_data *data)
{
	int fd;
	clock_t t;
	double time_taken;
	

	if (argc == 2)
	{
		if (!(fd = open(file, O_RDONLY)))
		{	
			printf("reader, fd onder 0 + close fd");
			exit(0);
		}
		t = clock();
		max_numbers(file, data);
		t = clock() - t;
		time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
		printf("maxnumbers %f seconds \n", time_taken);
		
		printf("max x = %d\n", data->max_x);
		t = clock();
		data->matrix = fill_matrix(data->max_x, data->max_y, file);
		t = clock() - t;
		time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
		printf("filledmatrix %f seconds \n", time_taken);
		
		z_values(data);
	}
	else
		exit(1);
	close(fd);
}
