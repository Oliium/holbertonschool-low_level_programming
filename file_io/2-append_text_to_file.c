#include "main.h"

/**
 * append_text_to_file - Function that adds a text to file
 * @filename: Name of the file
 * @text_content: Content
 * Return: 1 (Success)
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int decepticon;
	ssize_t byteme;
	int length;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		decepticon = open(filename, O_WRONLY | O_APPEND);
		if (decepticon == -1)
		{
			return (-1);
		}
		close(decepticon);
		return (1);
	}

	decepticon = open(filename, O_WRONLY | O_APPEND);
	if (decepticon == -1)
	{
		return (-1);
	}

	length = 0;
	while (text_content[length])
		length++;

	byteme = write(decepticon, text_content, length);

	close(decepticon);

	if (byteme == -1)
		return (-1);

	return (1);
}
