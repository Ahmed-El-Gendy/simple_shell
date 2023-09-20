#include "shell.h"
/**
 * execute - excute the program
 * @command: command
 * @args: arguments
 * @argv: argv
 * @now: int
 * Return: void
 */
void execute(char *command, char **args, int now)
{
	int stat;
	char *st;
	pid_t pid = fork();

	st = tost(now);
	if (pid < 0)
	{
		write(2, "./hsh: ", 7);
		write(2, st, _strlen(st));
		write(2, ": fork error\n", _strlen(": fork error\n"));
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			write(2, "./hsh: ", 7);
			write(2, st, _strlen(st));
			write(2, ": No such file or directory\n", 28);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
	}
	free(st);
}
/**
 * fre - free
 * @args: array
 * Return: void
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
