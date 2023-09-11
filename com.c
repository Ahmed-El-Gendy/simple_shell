#include "shell.h"

/**
 * con - to continue if condition found
 * @command: commad
 * @args: args
 * Return: 1 if true 0 if false
 */
int con(char **command, char **args)
{
	if (cmp(*command, "cd"))
	{
		change_dir(args);
		return (1);
	}
	if (!getpath(*command, _strlen(*command)))
	{
		_puts("No such file or directory\n");
		return (1);
	}
	return (0);
}
