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

	while (true)
	{
		if (check)
			_puts("saged$ ");
		input = our_get_line();
		if (input == NULL)
			break;
		if (rep(input))
		{
			continue;
		}
		comma(&input);
		free(input);
	}
	free(input);
	return (0);
}
