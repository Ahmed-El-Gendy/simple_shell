#include "shell.h"

/**
 * con - to continue if condition found
 * @command: commad
 * @args: args
 * @now: num of line
 * @argv: argv
 * @p: p
 * Return: 1 if true 0 if false
 */
int con(char **command, char ***args, int now, char **argv, char *p)
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
	if (cmp(*command, "setenv") || cmp(*command, "unsetenv"))
	{
		handle_env(command, args, n, argv);
		return (1);
	}
	if (cmp(*command, "env"))
	{
		if (call_env(n, argv))
			return (1);
	}
	if (cmp(*command, "cd"))
	{
		change_dir(&(*args)[1], now, argv, p);
		return (1);
	}
	if (!getpath((command), _strlen(*command), argv, now))
	{
		erp(now, *command);
		return (1);
	}
	return (0);
}

/**
 * erp - error
 * @now: int
 * @command: com
 * Return: void
 */
void erp(int now, char *command)
{
	char *s = to_st(now);

	write(2, "./hsh: ", 7);
	write(2, s, _strlen(s));
	write(2, ": ", 2);
	write(2, command,  _strlen(command));
	write(2, ": not found\n", _strlen(": not found\n"));
	free(s);
}
/**
 * call_env - call
 * @n: n
 * @argv: argv
 * Return: 1 or 0
 */
int call_env(int n, char **argv)
{
	int i;

	if (n == 1)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			_puts(argv[i]);
			_putchar('\n');
		}
		return (1);
	}
	return (0);
}

