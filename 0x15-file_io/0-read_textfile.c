#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @len_filename: The name of the file to read
 * @len_letters: The number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *len_filename, size_t len_letters)
{
	FILE *len_file;
	char *len_buffer;
	ssize_t len_bytes_read, len_bytes_written;

	if (len_filename == NULL)
		return (0);

	len_file = fopen(len_filename, "r");
	if (len_file == NULL)
		return (0);

	len_buffer = malloc(sizeof(char) * (len_letters + 1));
	if (len_buffer == NULL)
	{
		fclose(len_file);
		return (0);
	}

	len_bytes_read = fread(len_buffer, sizeof(char), len_letters, len_file);
	if (len_bytes_read == -1)
	{
		free(len_buffer);
		fclose(len_file);
		return (0);
	}

	len_buffer[len_bytes_read] = '\0';

	len_bytes_written = fwrite(len_buffer, sizeof(char), len_bytes_read, stdout);
	if (len_bytes_written != len_bytes_read)
	{
		free(len_buffer);
		fclose(len_file);
		return (0);
	}

	free(len_buffer);
	fclose(len_file);

	return (len_bytes_written);
}
