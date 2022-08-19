/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 12:35:31 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/19 15:14:07 by dyeboa        ########   odam.nl         */
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
			
			// matrix[x_i][y_i].colour = colour(x_i, y_i, file);
			y_i++;
		}
		x_i++;
	}
	matrix[x_i][y_i].z = height(x_i, y_i, file);
	//printlist(matrix, x, y);
	return (matrix);
}

// int	colour(int x, int y, char *file)
// {
// 	int fd;
// 	char **array;
// 	char *colour;
	
// 	fd = open(file, O_RDONLY);
// 	array = ft_split(get_next_line(fd), ' ');
// 	while(x > 0)
// 	{
// 		array = ft_split(get_next_line(fd), ' ');
// 		x--;
// 	}
// 	colour = ft_strchr(array[y], ',');
// 	if (colour && *colour)
// 		colour++;
// 	else
// 		return (0);
// 	close(fd);
// 	return (ft_atoi_base(colour, "0123456789ABCDEF"));
// }

// int	height(int x, int y, char *file)
// {
// 	int fd;
// 	char **array;

// 	fd = open(file, O_RDONLY);
// 	array = ft_split(get_next_line(fd), ' ');
// 	while(x > 0)
// 	{
// 		array = ft_split(get_next_line(fd), ' ');
// 		x--;
// 	}
// 	close(fd);
// 	return (ft_atoi(array[y]));
// }

int	height(int x, int y, char *file)
{
	int fd;
	char **array;
	char	*text;
	char		*line;
	ssize_t		i;

	fd = open(file, O_RDONLY);
	if (fd == -1 || BUFFER_SIZE < 1)
		return (0);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
        return (0);
	i = 1;
	while ((i != 0))
	{	
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (0);
		}
		line[i] = '\0';
		text = ft_strjoin(text, line);
	}
	//printf("%s", text);
	array = ft_split(text, ' ');
	while(x > 0)
	{
		array = ft_split(text, ' ');
		x--;
	}
	close(fd);
	printf("%s", array[y]);
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
			printf("x=%.0f ", matrix[i][j].x);
			//printf("x+1=%.0f ", matrix[i][j+1].x);
			printf("%.0f ", matrix[i][j].y);
			printf("%.0f ", matrix[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}