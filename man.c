#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
	char *buf;
	int fd = open("mybleives.txt",O_RDWR);
	write(fd, "hello world",11);
	write(fd, "1. BLIEVE THAT MONEY IS ALL",28);
	
		int fd2 = open("mybleives.txt",O_RDWR);
	buf = get_next_line(fd2);
	printf("%s", buf);
}