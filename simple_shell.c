#include "shell.h"

/**
 * main - The main function of our project
 *
 * Return: always 0
 */

int main(void)
{
	char *input, **argv;
	int check = isatty(STDIN_FILENO);
	int now = 1;

	argv = malloc(sizeof(char *) * 250);
	fill(&argv);
	while (1)
	{
		if (check)
			_puts("$ ");
		input = malloc(1024);
		if (fgets(input, 1024, stdin) == NULL)
		{
			_puts("\n");
            free(input);
            break;
        }
		if (rep(input))
		{
			free(input);
			continue;
		}
		if (chec(input, now))
			comma(&input, now, argv);
		free(input);
		now++;
	}
	fre_argv(argv);
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
	_puts("sh: ");
	print_int(now);
	_puts("Syntax error: \"");
	_putchar(';');
	_puts("\" unexpected\n");
}
/**
 * pt - error2
 * @now: int
 * Return: void
 */
void pt(int now)
{
	_puts("sh: ");
	print_int(now);
	_puts("Syntax error: \"");
	_putchar(';');
	_putchar(';');
	_puts("\" unexpected\n");
}
