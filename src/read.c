#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


void	reader(int argc, char *file)
{
	int fd;
    static char	*text;
	char		*line;
	ssize_t		i;
    if (fd == -1 || BUFFER_SIZE < 1)
		return (0);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
        return (NULL);
	if (argc == 2)
	{
		if (!(fd = open(file, O_RDONLY)))
		{	
			printf("reader, fd onder 0 + close fd");
			exit(0);
		}
        while (is_newline(text) == 0 && (i != 0))
        {	
            i = read(fd, line, BUFFER_SIZE);
            if (i == -1)
            {
                free(line);
                return (NULL);
            }
            line[i] = '\0';
            printf("%s\n", line);

        }
	}
	else
		exit(1);
	close(fd);
}

int	main(int argc, char **argv)
{
    reader(argc, argv[1]);
    return (0);
}