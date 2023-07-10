#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * error_exit - Prints an error message and exits the program with a given code
 * @exit_code: The exit code
 * @len_message: The error message to print
 */
void error_exit(int exit_code, const char *len_message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", len_message);
	exit(exit_code);
}

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, or the corresponding error code on failure
 */
int main(int argc, char *argv[])
{
	int len_fd_from, len_fd_to;
	ssize_t len_read, len_write;
	char len_buffer[BUF_SIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	len_fd_from = open(argv[1], O_RDONLY);
	if (len_fd_from == -1)
		error_exit(98, argv[1]);

	len_fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (len_fd_to == -1)
		error_exit(99, argv[2]);

	while ((len_read = read(len_fd_from, len_buffer, BUF_SIZE)) > 0)
	{
		len_write = write(len_fd_to, len_buffer, len_read);
		if (len_write == -1)
			error_exit(99, argv[2]);
	}

	if (len_read == -1)
		error_exit(98, argv[1]);

	if (close(len_fd_from) == -1)
		error_exit(100, "Can't close fd_from");

	if (close(len_fd_to) == -1)
		error_exit(100, "Can't close fd_to");

	return (0);
}
