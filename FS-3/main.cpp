#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFF_SIZE 4096

int main(int argc, char* argv[])
{
	if (argc < 2) 
	{
		printf("Invalid arguments\n");
		return 1
	}

	struct stat Stat;
	if (stat(argv[1], &Stat) != 0)
	{
		printf("Error\n");
		return 1;
	}

	int fd = open(argv[1], O_WRONLY);
	if (fd == -1)
	{
		printf("Something went wrong.\n");
		exit(errno);
	}

	off_t size = lseek(fd, 0, SEEK_END);
	char empty = '\0';

	for (off_t i = 0; i < size; i++)
	{
		if (write(fd, &empty, 1) != 1)
		{
			printf("Error\n");
			close(fd);
			exit(errno);
		}
	}

	close(fd);

	if (unlink(argv[1]) != 0) 
	{
		printf("Error\n");
		exit(errno);
	}
	printf("File deleted\n");

	return 0;
}
