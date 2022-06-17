
#include <stdio.h>
#include <sys/stat.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int fd;
	char *read_code;
	char *line = 0;
	int n;

	fd = open(argv[1], O_RDONLY);
	n = 0;
	if (argc != 2)
		printf("%d", argc);
	read_code = get_next_line(fd);
	while (read_code != 0 || read_code < 0)
	{
		read_code = get_next_line(fd);
		printf("%s", read_code);
		free(line);
	}
	close(fd);
	return (0);
}
