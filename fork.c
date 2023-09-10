#include "shell.h"
/**
 * execute - excute the program
 * @command: command
 * @args: arguments
 */
void execute(char *command, char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(command, args, environ);
		_puts("bash: ");
		_puts(command);
		_puts(": command not found\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
