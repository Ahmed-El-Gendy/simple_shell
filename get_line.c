#include "shell.h"

/**
 * our_get_line - get line function using read
 * Return: the input as get line function
 */

char *our_get_line(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;
	size_t total_bytes_read = 0;

	while (true)
	{
		if (total_bytes_read + 64 >= buffer_size)
		{
			buffer_size += 64;
			buffer = realloc(buffer, buffer_size);
			if (!buffer)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
		}
		bytes_read = read(STDIN_FILENO, buffer + total_bytes_read, 64);
		if (bytes_read == -1)
		{
			perror("Error reading input");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		else if (bytes_read == 0 && total_bytes_read == 0)
		{
			free(buffer);
			return (NULL);
		}
		total_bytes_read += bytes_read;
		if (buffer[total_bytes_read - 1] == '\n')
			break;
	}
	buffer[total_bytes_read] = '\0';
	return (buffer);
}
