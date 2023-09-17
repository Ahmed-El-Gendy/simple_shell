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
		if (chec(input, now))
			comma(&input, now);
		free(input);
		now++;
	}
	free(input);
	return (0);
}

/**
 * chec - to check ;
 * @input: string
 * @now: int
 * Return: 1 if ok 0 if fail
 */

int chec(char *input, int now)
{
	int i = 0, j = 0;

	for (i = 0; input[i] == ' ' && input[i] != '\0'; i++)
		;
	if (input[i] == ';')
	{
		_puts("sh: ");
		print_int(now);
		_puts("Syntax error: \";\" unexpected\n");
		return (0);
	}
	while (input[i] != '\0')
	{
		if (input[i] == ';')
		{
			j = i + 1;
			if (input[j] == ';')
			{
				_puts("sh: ");
				print_int(now);
				_puts("Syntax error: \";;\" unexpected\n");
				return (0);
			}
			while (input[j] != '\0' && input [j] == ' ')
				j++;
			if (input[j] == ';')
			{
				_puts("sh: ");
				print_int(now);
				_puts("Syntax error: \";\" unexpected\n");
				return (0);
			}
			i = j;
		}
		i++;
	}
	return (1);
}
