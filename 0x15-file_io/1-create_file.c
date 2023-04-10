#include "main.h"
#include <stdio.h>
#include <openssl/evp.h>
/**
 * main - This will copy the content of a file to another file
 * @argv: The argument vector
 * @argc: The argument count
 * Return: 0 on Success
 */
int main(int argc, char *argv[])
{
	int fo, fu, reader, writer;
	char buffer[1024];

	if (argc != 3)
	{dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fo = open(argv[1], O_RDONLY);
	if (fo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fu = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fu == -1)
	{dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	while ((reader = read(fo, buffer, 1024)) != 0)
	{
		if (reader == -1)
		{dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		writer = write(fu, buffer, reader);
		if (writer == -1)
		{dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
		}
		}

	if (close(fo) == -1)
	{dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fo), exit(100);
	}
	if (close(fu) == -1)
	{dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fu), exit(100);
	}
	return (0);
}
