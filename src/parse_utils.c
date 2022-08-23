/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 12:46:16 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/23 13:24:20 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	max_numbers(char *file, t_data *data)
{
	int		fd;
	int		ymax;
	int		i;
	char	*read_code;
	char	**line;

	i = 0;
	ymax = 0;
	fd = open(file, O_RDONLY);
	read_code = get_next_line(fd);
	if (!read_code)
		return ;
	line = ft_split(read_code, ' ');
	free(read_code);
	while (line[i] && line)
		i++;
	while (read_code != 0 && ymax++ >= 0)
	{
		read_code = get_next_line(fd);
		free(read_code);
	}
	data->max_x = i;
	data->max_y = ymax;
	free_arr(line);
	close(fd);
}

void	z_values(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	data->max_z = 0;
	data->min_z = 0;
	while (x < data->max_y)
	{
		y = 1;
		while (y < data->max_x)
		{
			if (data->max_z < data->matrix[x][y].z)
				data->max_z = data->matrix[x][y].z;
			if (data->min_z > data->matrix[x][y].z)
				data->min_z = data->matrix[x][y].z;
			if (((data->max_z > -11 && data->max_z < 11)) && (data->max_x < 50 \
				&& data->max_y < 50) && data->max_y != 11)
				data->matrix[x][y].z *= 10;
			y++;
		}
		x++;
	}
}

void	reader(int argc, char *file, t_data *data)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0 || !fd)
		{	
			write(1, "No file ", 8);
			write(1, file, ft_strlen(file));
			write(1, "\n", 2);
			exit(0);
		}
		max_numbers(file, data);
		data->matrix = fill_matrix(data->max_x, data->max_y, file);
		z_values(data);
	}
	else
	{	
		write(1, "No file ", 8);
		write(1, file, ft_strlen(file));
		write(1, "\n", 2);
		exit(0);
	}
	close(fd);
}
