#include "main.h"

/**
 * close_or_die - Closes a file descriptor or exits with code 100.
 * @fd: File descriptor to close.
 */

void close_or_die(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_from_file - Opens source file for reading.
 * @filename: Source file name.
 *
 * Return: Open file descriptor.
 */

int open_from_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_to_file - Opens destination file for writing.
 * @filename: Destination file name.
 * @fd_from: Source file descriptor to close on error.
 *
 * Return: Open file descriptor.
 */

int open_to_file(char *filename, int fd_from)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		close_or_die(fd_from);
		exit(99);
	}
	return (fd);
}

/**
 * copy_file_content - Copies bytes from one fd to another.
 * @fd_from: Source file descriptor.
 * @fd_to: Destination file descriptor.
 * @to_name: Destination file name for error display.
 * @from_name: Source file name for error display.
 */

void copy_file_content(int fd_from, int fd_to, char *to_name, char *from_name)
{
	ssize_t bytes_read;
	ssize_t bytes_written;
	char buffer[1024];

	bytes_read = read(fd_from, buffer, 1024);
	while (bytes_read > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to_name);
			close_or_die(fd_from);
			close_or_die(fd_to);
			exit(99);
		}
		bytes_read = read(fd_from, buffer, 1024);
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_name);
		close_or_die(fd_from);
		close_or_die(fd_to);
		exit(98);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @argc: Number of arguments.
 * @argv: Arguments array.
 *
 * Return: Always 0 on success.
 */

int main(int argc, char *argv[])
{
	int fd_from;
	int fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_from_file(argv[1]);
	fd_to = open_to_file(argv[2], fd_from);
	copy_file_content(fd_from, fd_to, argv[2], argv[1]);
	close_or_die(fd_from);
	close_or_die(fd_to);

	return (0);
}
