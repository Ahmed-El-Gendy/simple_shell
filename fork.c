#include "shell.h"
/**
 * execute - excute the program
 * @command: command
 * @args: arguments
 * @now: now
 * @argv: arg
 */
void execute(char *command, char **args, char **argv, int now)
{
	char *s = to_st(now);
	pid_t pid = fork();

	argv = argv;
	if (pid == 0)
	{
		execve(command, args, argv);
		write(2, "./hsh: ", 7);
		write(2, s, _strlen(s));
		write(2, ": ", 2);
		write(2, command, _strlen(command));
		write(2, ": No such file or directory\n", 28);
		fre(argv);
		fre(args);
		free(s);
		exit(127);
	}
	else
	{
		wait(NULL);
		free(s);
	}
}
/**
 * fre - free
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
