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
	struct stat s;
	int check = isatty(STDIN_FILENO), read;
	int now = 1;
	char **argv;
	unsigned long int len;

	argv = malloc(sizeof(char *) * 250);
	fill(&argv);
	while (true)
	{
		if (check)
			_puts("saged$ ");
		/*input = our_get_line();*/
		read = getline(&input, &len, stdin);
		if (read == -1)
			break;
		if (rep(input))
		{
			continue;
		}
		if (chec(input, now))
			comma(&input, now, argv);
		now++;
	}
	fre_argv(argv);
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
