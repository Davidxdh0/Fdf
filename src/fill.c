/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 12:35:31 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/26 17:46:09 by dyeboa        ########   odam.nl         */
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
			matrix[x_i][y_i].x = 1;
			matrix[x_i][y_i].y = 1;
			y_i++;
		}
		x_i++;
	}
	height(x, y, file, matrix);
	return (matrix);
}

void	height(int x, int y, char *file, t_matrix **matrix)
{
	int		fd;
	char	**array;
	char	*temp;
	int		j;
	int		i;

	i = -1;
	fd = open(file, O_RDONLY);
	while (++i < y && fd != 0)
	{
		j = -1;
		temp = get_next_line(fd);
		if (temp)
		{
			array = ft_split(temp, ' ');
			while (++j < x && array)
			{
				matrix[i][j].z = ft_atoi(array[j]);
				free(array[j]);
			}
			free(array);
		}
		free(temp);
	}
	close(fd);
}

// void	printlist(t_matrix **matrix, int x, int y)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < y)
// 	{
// 		j = 0;
// 		while(j < x)
// 		{
// 			// if (j == 11)
// 			{
// 				printf("x=%.0f ", matrix[i][j].x);
// 				//printf("x+1=%.0f ", matrix[i][j+1].x);
// 				printf("y = %.0f ", matrix[i][j].y);
// 				printf("z = %.0f ", matrix[i][j].z);
// 			}
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }