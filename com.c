#include "shell.h"

/**
 * con - to continue if condition found
 * @command: commad
 * @args: args
 * @now: num of line
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
	if (cmp(*command, "setenv") || cmp(*command, "unsetenv"))
	{
		handle_env(command, args, n);
		return (1);
	}
	if (cmp(*command, "env"))
	{
		if (n == 1)
		{
			for (i = 0 ; environ[i] != NULL; i++)
			{
				_puts(environ[i]);
				_putchar('\n');
			}
			return (1);
		}
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
 * Return: void
 */
void erp(int now, char *command)
{
	_puts("sh: ");
	print_int(now);
	_puts(command);
	_puts(": not found\n");
}
