/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/05 08:09:44 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/19 15:06:21 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reader2(char *str)
{
	char	*text;
	char		*line;
	ssize_t		i;
	int fd;
	
	fd = open(str, O_RDONLY);
    if (fd == -1 || BUFFER_SIZE < 1)
		return ;
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
        return ;
	i = 1;
	while ((i != 0))
	{	
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return ;
		}
		line[i] = '\0';
		text = ft_strjoin(text, line);
	}
	printf("%s", text);
	close(fd);
}

int	main(int argc, char **argv)
{
	// argc++;
	// reader2(argv[1]);
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
   // printf("create %f seconds \n", time_taken);
	t = clock();
	draw(&data);
   	t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    //printf("draw %f seconds \n", time_taken);
	//printlist(data.matrix, data.max_x, data.max_y);
	t = clock();
	mlx_hook(data.win, 2, 1L<<0, keypress, &data);
	mlx_loop(data.mlx);
   	t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    //printf("mlx %f seconds \n", time_taken);
	
	return (0);
}
//printf("x=%d, y=%d", data.max_x, data.max_y );