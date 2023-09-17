#include "shell.h"

/**
 * con - to continue if condition found
 * @command: commad
 * @args: args
 * Return: 1 if true 0 if false
 */
int con(char **command, char ***args)
{
	int n = len_args(args), i = 0;

	if (cmp(*command, "setenv") || cmp(*command, "unsetenv"))
	{
		handle_env(command,args,n);
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
		change_dir(&(*args)[1]);
		return (1);
	}
	if (!getpath((command), _strlen(*command)))
	{
		_puts("No such file or directory\n");
		return (1);
	}
	return (0);
}
