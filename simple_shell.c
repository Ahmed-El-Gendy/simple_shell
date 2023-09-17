#include "shell.h"

/**
 * main - The main function of our project
 *
 * Return: always 0
 */

int main(void)
{
	signal(SIGINT, SIG_IGN);

	char *input = NULL;
	size_t len = 0;
	struct stat s;
	int check = isatty(STDIN_FILENO);
	int now = 1;

	while (true)
	{
		if (check)
			_puts("saged$ ");
		input = our_get_line();
		if (input == NULL)
			break;
		if (rep(input))
		{
			free(input);
			continue;
		}
		comma(&input, now);
		free(input);
		now++;
	}
	free(input);
	return (0);
}
