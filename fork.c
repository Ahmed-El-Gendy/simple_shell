#include "shell.h"
/**
 * execute - excute the program
 * @command: command
 * @args: arguments
 * @now: now
 * @argv: arg
 * @p: p
 * Return: int
 */
int execute(char *command, char **args, char **argv, int now, char *p)
{
	char *s;
	int st;
	pid_t pid = fork();

	argv = argv;
	if (pid == 0)
	{
		fre(argv);
		free(p);
		execve(command, args, environ);
		s = to_st(now);
		write(2, "./hsh: ", 7);
		write(2, s, _strlen(s));
		write(2, ": ", 2);
		write(2, command, _strlen(command));
		write(2, ": No such file or directory\n", 28);
		fre(args);
		free(s);
		exit(127);
	}
	else
	{
		waitpid(pid, &st, 0);
	}
	return (WEXITSTATUS(st));
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
