#include "main.h"

/**
 * read_textfile - Function that reads a text file and prints the output
 * @filename: Name of the file
 * @letters: number of letters it should print
 * open(pathname, flags(Read only, write etc..), mode(when creating a file))
 * read(description of the file, where the text is stocked, what it reads)
 * write(where to write, where its stocked, what it writes)
 * Return: The text
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int decepticon; /* Description of the file*/
	ssize_t rd;		/*Read variable*/
	ssize_t wr;		/* Write Variable*/
	char *buffer;	/* stocks the text*/

	if (filename == NULL)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
	{
		return (0);
	}
	decepticon = open(filename, O_RDONLY);
	if (decepticon == -1)
	{
		free(buffer);
		return (0);
	}
	rd = read(decepticon, buffer, letters);
	if (rd == -1)
	{
		free(buffer);
		close(decepticon);
		return (0);
	}
	wr = write(STDOUT_FILENO, buffer, rd);
	if (wr == -1 || wr != rd)
	{
		free(buffer);
		close(decepticon);
		return (0);
	}
	free(buffer);
	close(decepticon);

	return (wr);
}
