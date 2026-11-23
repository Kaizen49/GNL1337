
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
int main()
{
	int	fd = open("test.txt", O_RDONLY);

	int fd2 = dup(fd);

	char *line = get_next_line(fd);
	printf("%s",line);
	free(line);
	line = get_next_line(fd2);
	printf("%s",line);
	free(line);

}