#include "main.h"
#include <stdio.h>
/**
 * main - This file will copies the content of a file to another file
 * @argv: The argument vector
 * @argc: the argument count
 * Return: wil return 0 on Success
 */
int main(int argc, char *argv[])
{
	int fo, fu, reading, writing;
	char buffer[1024];

	if (argc != 3)
	{dprintf(STDERR_FILENO, "Usage: copy file_from file_to\n");
		exit(97);
	}

	fo = open(argv[1], O_RDONLY);
	if (fo == -1)
	{
		dprintf(STDERR_FILENO, "Fatal Error: I Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fu = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fu == -1)
	{dprintf(STDERR_FILENO, "Err:I  Can't write to %s\n", argv[2]), exit(99);
	}

	while ((reading = read(fo, buffer, 1024)) != 0)
	{
		if (reading == -1)
		{dprintf(STDERR_FILENO, "Fatal Err: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		writing = write(fu, buffer, reading);
		if (writing == -1)
		{dprintf(STDERR_FILENO, " Err: Can't write to %s\n", argv[2]), exit(99);
		}
	}

	if (close(fo) == -1)
	{dprintf(STDERR_FILENO, "Fatl Error: Can't close fd %d\n", fo), exit(100);
	}
	if (close(fu) == -1)
	{dprintf(STDERR_FILENO, "Fatal Error: Can't close fd %d\n", fu), exit(100);
	}
	return (0);
}
