#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file with the given filename and writes
 *               the text content to the file
 * @len_filename: The name of the file to create
 * @len_text_content: The text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *len_filename, char *len_text_content)
{
	int len_fd, len_write_status, len_text_length = 0;

	if (len_filename == NULL)
		return (-1);

	if (len_text_content != NULL)
	{
		while (len_text_content[len_text_length])
			len_text_length++;
	}

	len_fd = open(len_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (len_fd == -1)
		return (-1);

	len_write_status = write(len_fd, len_text_content, len_text_length);
	if (len_write_status == -1)
	{
		close(len_fd);
		return (-1);
	}

	close(len_fd);
	return (1);
}
