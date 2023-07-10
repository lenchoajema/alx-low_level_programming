#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
ssize_t read_textfile(const char *len_filename, size_t len_letters);
int create_file(const char *len_filename, char *len_text_content);
int append_text_to_file(const char *len_filename, char *len_text_content);

#endif /* MAIN_H */
