#include "main.h"
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
 * append_text_to_file - function to create a file
 * @filename: pointer variable hold file name
 * @text_content: pointer variable contain file content
 * Return: for 1 on success otherwise -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t wf = 0;
	int file;

	if (!filename)
		return (-1);
	file = open(filename, O_WRONLY | O_APPEND);
	if (file < 0)
		return (-1);
	if (text_content)
		wf = write(file, text_content, _strlen(text_content));

	close(file);
	if (wf < 0)
		return (-1);
	return (1);
}
