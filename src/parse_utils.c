/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 12:46:16 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/16 13:30:29 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int county(char *file)
{
	int fd;
	int ymax;
	char *read_code;

	fd = open(file, O_RDONLY);
	ymax = 0;
	read_code = get_next_line(fd);
	while (read_code != 0)
	{
		//printf("%s", read_code);
		read_code = get_next_line(fd);
		ymax++;
	}
	free(read_code);
	close(fd);
	return (ymax);
}

int countx(char *file)
{
	int fd;
	char *read_code;
	char **array;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	array = ft_split(get_next_line(fd), ' ');
	while(array[i])
		i++;
	free(array);
	while(1)
	{
		read_code = get_next_line(fd);
		if (!read_code)
			break ;
		array = ft_split(read_code, ' ');
		while(array[j])
			j++;
		if (j != i)
		{
			free(array);
			printf("min x = %d, max x = %d\n", j, i);
			return (0);
		}
	}	
	free(read_code);
	free(array);
	close(fd);
	return (i);
}


