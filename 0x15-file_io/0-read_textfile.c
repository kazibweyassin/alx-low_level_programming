#include "main.h"
/**
 * read_textfile - this functions reads a text file and prints it posix
 * @filename : name of the file
 * @letters: the number of letters
 *
 * Return: This returns the number of letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor, bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)

	{
		free(buffer);
		return (0);
	}


	bytes_read = read(file_descriptor, buffer, letters);

	if (bytes_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	bytes_written  = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	free(buffer);
	close(file_descriptor);

	return (bytes_written);
}
