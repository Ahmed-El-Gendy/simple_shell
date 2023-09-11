#include "shell.h"

/**
 * main - The main function of our project
 *
 * Return: always 0
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	struct stat s;
	int check = isatty(STDIN_FILENO);

	while (true)
	{
		input = NULL;
		if (check)
			_puts("saged$ ");
		if (getline(&input, &len, stdin) == -1)
			break;
		if (rep(&input))
			continue;
		char *command = NULL, **args = NULL;

		split(input, &command, &args);
		if (cmp(command, "exit"))
		{
			int k;

			if (!convert(&args, &k))
				break;
			exit(k);
		}
		if (con(command, args[1]))
			continue;
		else
			command = getpath(command, _strlen(command));
		execute(command, args);
	}
	free(input);
	return (0);
}
