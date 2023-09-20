#include "shell.h"

/**
 * main - The main function of our project
 * @ac: int
 * @av: array
 * @env: array
 * Return: always 0
 */

int main(void)
{
	char *input;
	int check = isatty(STDIN_FILENO);
	int now = 1;

	while (true)
	{
		if (check)
			write(STDOUT_FILENO, "$ ", 2);
		input = our_get_line();
		if (input == NULL)
		{
			_puts("\n");
			break;
		}
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
		ptt(now);
		return (0);
	}
	while (input[i] != '\0')
	{
		if (input[i] == ';')
		{
			j = i + 1;
			if (input[j] == ';')
			{
				pt(now);
				return (0);
			}
			while (input[j] != '\0' && input[j] == ' ')
				j++;
			if (input[j] == ';')
			{
				ptt(now);
				return (0);
			}
			i = j;
		}
		i++;
	}
	return (1);
}
/**
 * ptt - error
 * @now: int
 * Return: void
 */
void ptt(int now)
{
	now = now;
	perror("No such file or directory");
}
/**
 * pt - error2
 * @now: int
 * Return: void
 */
void pt(int now)
{
	now = now;
	perror("No such file or directory");
}
