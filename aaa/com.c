#include "shell.h"

/**
 * con - to continue if condition found
 * @command: commad
 * @args: args
 * @now: num of line
 * @argv: argv
 * Return: 1 if true 0 if false
 */
int con(char **command, char ***args, int now)
{
	int n = len_args(args), i = 0, j = 0;

	while ((*command)[j] != '\0')
	{
		j++;
		if ((*command)[j] != ' ')
		{
			i++;
			break;
		}
	}
	if (!i)
		return (1);
	i = 0;
	if (cmp(*command, "env"))
	{
		if (call_env(n))
			return (1);
	}
	if (cmp(*command, "cd"))
	{
		if (n > 2)
		{
			_puts("erorr\n");
			return (1);
		}
		change_dir(&(*args)[1], now);
		return (1);
	}
	if (!getpath((command), _strlen(*command)))
	{
		erp(now, *command);
		return (1);
	}
	return (0);
}

/**
 * erp - error
 * @now: int
 * @command: command
 * Return: void
 */
void erp(int now, char *command)
{
	char *st;

	st = tost(now);
	now = now;
	command = command;
	write(2, "./hsh: ", 7);
	write(2, st, _strlen(st));
	write(2, ": ", 2);
	write(2, command, _strlen(command));
	write(2, ": not found\n", strlen(": not found\n"));
	free(st);
}
/**
 * call_env - call
 * @n: n
 * @argv: argv
 * Return: 1 or 0
 */
int call_env(int n)
{
	int i;

	if (n == 1)
	{
		for (i = 0 ; environ[i] != NULL; i++)
		{
			_puts(environ[i]);
			_putchar('\n');
		}
		return (1);
	}
	return (0);
}

