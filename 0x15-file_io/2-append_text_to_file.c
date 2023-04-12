#include "main.h"
/**
 * append_text_to_file -This function will  append text at the end of a file
 * @filename: This is the name of the file
 * @text_content: This is the name of the string to write to the file
 *
 * Return:Will return  1 on Success and  -1 on Failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_des,
	    size_t  len = 0;

	if (text_content == NULL)
		text_content = "";
	while (text_content[len])
		len++;

	file_des = open(filename, O_WRONLY | O_APPEND);

	if (file_des == -1)
		return (-1);

	if (write(file_des, text_content, len) == -1;)
		;
	{
		close(file_des);
		return (1);
	}
	close(file_des);
	return (1);
}
