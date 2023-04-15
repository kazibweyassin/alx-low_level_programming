#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * create_file - creates a file and write to it
 * @filename:  filename to create
 * @text_content:  text to write to it
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int desc, text_size;
	ssize_t wstat;

	if (!filename)
		return (-1);

	/*first call is to create file only if non-existent*/
	desc = open(filename, O_RDWR | O_CREAT | O_EXCL, 0600);
	if (desc < 0)
		desc = open(filename, O_RDWR | O_TRUNC);
	if (desc < 0)
		return (-1);
	if (!text_content || text_content[0] == '\0')
	{
		close(desc);
		return (1);
	}

	for (text_size = 0; text_content[text_size]; text_size++)
		;
	wstat = write(desc, text_content, text_size);

	close(desc);
	if (wstat != text_size)
		return (-1);
	return (1);

}
