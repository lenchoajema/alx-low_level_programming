#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _strlen - a function to  count length of the content
 * @str: pointer variable of content
 * Return: return leght of the content or -1 if it is null
 */
ssize_t _strlen(const char *str)
{
	ssize_t len = 0;

	if (!str)
		return (-1);
	while (*str++)
		++len;
	return (len);
}
/**
 * create_file - function to create a file
 * @filename: pointer variable hold file name
 * @text_content: pointer variable contain file content
 * Return: for 1 on success otherwise -1
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t wf = 0;
	int file;

	if (!filename)
		return (-1);
	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (file < 0)
		return (-1);
	if (text_content)
		wf = write(file, text_content, _strlen(text_content));

	close(file);
	if (wf < 0)
		return (-1);
	return (1);
}
