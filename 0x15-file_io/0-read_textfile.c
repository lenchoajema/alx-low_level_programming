#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * read_textfile - read a text file and print it to stdout
 * @filename: the name of the file to read
 * @letters: the number of letters to be read and printed
 *
 * Return: If filename is NULL, the file cannot be opened or read, or
 * write fails or returns an unexpected number of bytes, return 0.
 * Otherwise, return the actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer1 = NULL;
	ssize_t b_read1;
	ssize_t b_written1;
	int fd1;

	if (!(filename && letters))
		return (0);

	fd1 = open(filename, O_RDONLY);
	if (fd1 == -1)
		return (0);

	buffer1 = malloc(sizeof(char) * letters);
	if (!buffer1)
		return (0);

	b_read1 = read(fd1, buffer1, letters);
	close(fd1);

	if (b_read1 < 0)
	{
		free(buffer1);
		return (0);
	}
	if (!b_read1)
		b_read1 = letters;

	b_written1 = write(STDOUT_FILENO, buffer1, b_read1);
	free(buffer1);

	if (b_written1 < 0)
		return (0);

	return (b_written1);
}
