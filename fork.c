#include "shell.h"
/**
 * execute - excute the program
 * @command: command
 * @args: arguments
 */
void execute(char *command, char **args, char **argv)
{
	pid_t pid = fork();

	argv = argv;
	if (pid < 0)
	{
		write(2, "./hsh", 5);
		write(2, ": fork error\n", _strlen(": fork error\n"));
	}
	if (pid == 0)
	{
		execve(command, args, environ);
		write(2, "./hsh", 5);
		write(2, ": No such file or directory\n", strlen(": No such file or directory\n"));
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * fre - free
 * @command: string
 * @args: array
 */
void fre(char **args)
{
	int i = 0;

	if (!args)
		return;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
