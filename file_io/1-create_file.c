#include "main.h"

/**
 * create_file - Function that creates a file
 * @filename: name of the file
 * @text_content: The text to print
 * Return: 1 (FIle was created)
 */

int create_file(const char *filename, char *text_content)
{
	int decepticon;
	int length = 0;
	ssize_t byteme;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		while (text_content[length])
		{
			length++;
		}
	}
	decepticon = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (decepticon == -1)
	{
		return (-1);
	}
	if (length > 0)
	{
		byteme = write(decepticon, text_content, length);
		if (byteme == -1 || byteme != length)
		{
			close(decepticon);
			return (-1);
		}
	}
	/* Closes the file */
	if (close(decepticon) == -1)
	{
		return (-1);
	}

	return (1);
}
