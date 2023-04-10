#include "main.h"
#include <fcntl.h>
#include <unistd.h>
/**
 * create_file - creates a file
 * @filename: name of the file
 * @text_content: string to write to the file
 *
 * Return: 1 on Success or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_des, j, written_bytes;

	if (filename == NULL)
	{
		return (-1);
	}

	file_des = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_des == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		text_content = "";
	}

	for (j = 0 ; text_content[j] != '\0'; j++)
		;

	written_bytes = write(file_des, text_content, j);

	if (written_bytes == -1)
	{
		return (-1);
	}

	close(file_des);
	return (1);
}
