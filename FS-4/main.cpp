#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void initialize(int argc, char** argv)
{
	if (argc < 2) 
	{
		printf("Invalid arguments\n");
		return 1;
	}

	int c = close(0);
	if (c == -1) 
	{
		printf("Can't close stdout\n");
		exit(errno);
	}

	int f = open(argv[1], O_RDONLY);
	if (f == -1) 
	{
		printf("Something went wrong\n");
		exit(errno);
	}
}

int main(int argc, char** argv)
{
	// initialize the program based on the requirements
	initialize(argc, argv);

	// read the string 
	std::string input;
	std::cin >> input;

	std::string reversed(input.rbegin(), input.rend());
	
	// print to the console
	std::cout << reversed << std::endl;
	return 0;
}
