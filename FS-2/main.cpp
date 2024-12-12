#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFF_SIZE 4096

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("Invalid arguments\n");
		exit(1);
	}

	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);

	if (fd1 == -1 || fd2 == -1)
	{
		printf("Something went wrong.\n");
		exit(errno);
	}

	char* buff = (char*)malloc(BUFF_SIZE);
	long allBytes = 0;
	long readBytes = 0;
	while (true)
	{
		readBytes = read(fd1, buff, BUFF_SIZE);
		if (readBytes == -1)
		{
			printf("Something went wrong.\n");
			exit(errno);
		}

		if (readBytes == 0)
			break;

		allBytes += readBytes;
		long writeBytes = write(fd2, buff, (size_t)readBytes);

		if (writeBytes == -1)
		{
			printf("Something went wrong. Error\n");
			exit(errno);
		}

	}

	close(fd1);
	close(fd2);
	free(buff);
	printf("Bytes copied: %ld\n", allBytes);

	return 0;
}