#include "get_next_line.h"

int main()
{
    char    *line;
	int     fd;

	fd = open("get_next_line.h", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}