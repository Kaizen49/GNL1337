#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char buf[3];

	int fd = open("text.txt", O_CREAT | O_RDWR, 0644);
	write(fd, "Hello", 5);
	close(fd);
	fd1 = open("text.txt", O_RDWR);
	read(fd, buf, 2);
	buf[2] = '\0';
	write(1, buf, 2);
	close(fd);
}
open file description 
int fd2;
fd2 = dup(fd);