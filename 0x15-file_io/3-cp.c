#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define ARGERR 97
#define ARGMESS "Usage: cp file_from file_to\n"

#define RERR 98
#define RMESS "Error: Can\'t read from file %s\n"

#define WERR 99
#define WMESS "Error: Can\'t write to %s\n"

#define CLERR 100
#define CLMESS "Error: Can\'t close fd %i\n"

/**
 * errexit - exit with an error
 * @stat: the exit status
 * @estr: an extra string
 * @eint: an extra int
 */
void errexit(int stat, char *estr, int eint)
{
	if (stat == CLERR)
		dprintf(STDERR_FILENO, CLMESS, eint);
	else if (stat == ARGERR)
		dprintf(STDERR_FILENO, ARGMESS);
	else if (stat == WERR)
		dprintf(STDERR_FILENO, WMESS, estr);
	else
		dprintf(STDERR_FILENO, RMESS, estr);

	exit(stat);
}

/**
 * myclose - close a file and exit with error if impossible
 * @fd: the file descriptor to close
 */
void myclose(int fd)
{
	if (close(fd) < 0)
		errexit(CLERR, NULL, fd);
}


/**
 * initwrite - initialize the write file
 * @filename: the filename to initialize
 * Return: the file descriptor to check if negative
 */
int initwrite(char *filename)
{
	int desc;

	desc = open(filename, O_WRONLY | O_APPEND);
	if (desc < 0)
		desc = open(filename, O_WRONLY | O_EXCL | O_CREAT, 0664);
	if (desc < 0)
		errexit(WERR, filename, 0);
	myclose(desc);
	return (desc);
}

/**
 * main - the main function
 * @argc: the argument count
 * @argv: the arguments
 * Return: 0 if no problems, otherwise various error values
 */
int main(int argc, char **argv)
{
	int desc, i, outdesc;
	ssize_t ret, wstat;
	char stuff[1024];

	if (argc != 3)
		errexit(ARGERR, NULL, 0);

	if (!(argv[1]))
		errexit(RERR, argv[1], 0);

	desc = open(argv[1], O_RDONLY);

	if (desc < 0)
		errexit(RERR, argv[1], 0);

	if (!(argv[2]) || initwrite(argv[2]) < 0)
		errexit(WERR, argv[2], 0);
	outdesc = open(argv[2], O_WRONLY | O_TRUNC);

	while (1)
	{
		for (i = 0; i < 1024; i++)
			stuff[i] = 0;

		ret = read(desc, stuff, 1024);

		if (ret < 0)
			errexit(RERR, argv[1], 0);

		wstat = write(outdesc, stuff, ret);
		if (wstat != ret)
			errexit(WERR, argv[2], 0);
		if (wstat != 1024)
			break;

	}
	myclose(outdesc);
	myclose(desc);

	return (0);
}
