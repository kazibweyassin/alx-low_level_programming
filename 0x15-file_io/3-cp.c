#include "main.h"
/**
 * main - This is the proram program to copy
 * @ac: The argument count
 * @av: The array of arguments
 * Return: This will return a value
 */
int main(int ac, char **av)
{
	int fdFrum, fd, just_wrote, reading;
	char buff[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fdFrum = open(av[1], O_RDONLY);
	if (fdFrum == -1)
	{
		perror(STDERR_FILENO, "Err: Can't read from file %s\n", av[1]);
		exit(98);
	}
	fd = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		perror(STDERR_FILENO, "Err: Can't write to %s\n", av[2]);
		exit(99);
	}
	while ((reading = read(fdFrum, buff, 1024)) > 0)
	{
		just_wrote = write(fd, buff, reading);
		if (just_wrote == -1)
		{
			dprintf(STDERR_FILENO, "Er: Can't write to %s\n", av[2]);
			exit(99);
		}
	}
	if (reading == -1)
	{
		perror(STDERR_FILENO, "Er: Can't read from file %s\n", av[1]);
		exit(98);
	}
	if (close(fdFrum) == -1)
	{
		perror(STDERR_FILENO, "Er: Can't close fd %d", fdFrum);
		exit(100);
	}
	if (close(fd) == -1)
	{
		perror(STDERR_FILENO, "Er: Can't close fd %d", fd);
		exit(100);
	}
	return (0);
}
