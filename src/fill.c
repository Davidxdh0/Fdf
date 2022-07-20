/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 12:35:31 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/07/20 14:50:18 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	**fill_matrix(int x, int y, char *file)
{
	t_matrix	**matrix;
	int			x_i;
	int			y_i;

	matrix = malloc(y * sizeof(t_matrix *));
	if (!matrix)
		return (NULL);
	x_i = 0;
	while (x_i < y)
	{
		matrix[x_i] = malloc(x * sizeof(t_matrix));
		if (!matrix[x_i])
			return (NULL);
		y_i = 0;
		while (y_i < x)
		{
			// matrix[x_i][y_i].x = y_i;
			// matrix[x_i][y_i].y = x_i;
			matrix[x_i][y_i].z = height(x_i, y_i, file);
			matrix[x_i][y_i].colour = colour(x_i, file);
			//printf("%d ", matrix[x_i][y_i].colour);
			y_i++;
		}
		x_i++;
	}
	//printlist(matrix, x, y);
	return (matrix);
}

int	colour(int x, char *file)
{
	int fd;
	char **array;
	int i;
	int j;
	char *colour;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	array = ft_split(get_next_line(fd), ' ');
	while(x > 0)
	{
		array = ft_split(get_next_line(fd), ' ');
		x--;
	}
	colour = ft_strchr(array[0], ',');
	if (colour && *colour)
		colour++;
	else
		return (0);
	close(fd);
	return (ft_atoi_base(colour, "0123456789ABCDEF"));
}

int	height(int x, int y, char *file)
{
	int fd;
	char **array;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	array = ft_split(get_next_line(fd), ' ');
	while(x > 0)
	{
		array = ft_split(get_next_line(fd), ' ');
		x--;
	}
	close(fd);
	return (ft_atoi(array[y]));
}

void	printlist(t_matrix **matrix, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while(j < x)
		{
			//printf("%.0f ", matrix[i][j].x);
			//printf("%.0f ", matrix[i][j].y);
			printf("%.0f ", matrix[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}