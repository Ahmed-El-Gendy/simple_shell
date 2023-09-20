#include "shell.h"
/**
 * execute - excute the program
 * @command: command
 * @args: arguments
 */
void execute(char *command, char **args, char **argv, int now)
{
	char *st;
	pid_t pid = fork();

	st = tost(now);
	argv = argv;
	if (pid < 0)
	{
		write(2, "./hsh: ", 7);
		write(2, st, _strlen(st));
		write(2, ": fork error\n", _strlen(": fork error\n"));
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(command, args, argv);
		write(2, "./hsh: ", 7);
		write(2, st, _strlen(st));
		write(2, ": No such file or directory\n", strlen(": No such file or directory\n"));
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	free(st);
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
