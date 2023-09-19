#include "shell.h"
/**
 * execute - excute the program
 * @command: command
 * @args: arguments
 */
void execute(char *command, char **args, char **argv)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(command, args, argv);
		_puts("No such file or directory\n");
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
