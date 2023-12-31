#include "shell.h"

/**
 * comma - to split commands and handle (;) case
 * @input: pointer to the input as string
 * @now: numper of the line we reach for error
 * @argv: enviroment
 * @st: status
 * Return: void
 */
void comma(char **input, int *now, char **argv, int *st)
{
	char *input2, **args, *command;
	int i = 0, j = 0, k = 0;

	for (j = 0; ; j++)
	{
		if ((*input)[j] == ';' || (*input)[j] == '\0' || (*input)[j] == '#')
		{
			if (j == i)
			{
				i = j + 1;
				if ((*input)[j] == '\0' || (*input)[j] == '#')
					break;
				continue;
			}
			input2 = malloc(sizeof(char) * (j - i + 1));
			for (k = 0; i < j; i++, k++)
				input2[k] = (*input)[i];
			input2[k] = '\0';
			split(input2, &command, &args), value(args, argv), free(input2);
			if (cmp(command, "exit"))
			{
				if (!convert(&args, &k))
					fro(input, &args, *st, *now, st, argv);
				fro(input, &args, k, *now, st, argv), fre(args), i = j + 1;
				continue;
			}
			if (con(&command, &args, *now, argv, *input))
			{
				fre(args), i = j + 1;
				if ((*input)[j] == '\0' || (*input)[j] == '#')
					break;
				continue;
			}
			else
				getpath(&command, _strlen(command), argv, *now);
			*st = d(command, args, &i, j, argv, *now, *input);
		}
		if ((*input)[j] == '\0' || (*input)[j] == '#')
			break;
	}
}

/**
 * d - to free lines
 * @command: string
 * @args: array
 * @i: int
 * @j: int
 * @argv: enviroment
 * @n: now
 * @p: p
 * Return: the exit statue
 */
int d(char *command, char **args, int *i, int j, char **argv, int n, char *p)
{
	int st;

	args[0] = command;
	st = execute(command, args, argv, n, p);
	fre(args);
	*i = j + 1;
	return (st);
}
/**
 * fro - free
 * @args: array
 * @input: string
 * @k: int
 * @now: now
 * @st: st
 * @argv: enviroment
 * Return: void
 */
void fro(char **input, char ***args, int k, int now, int *st, char **argv)
{
	char *s = to_st(now);

	if (k < 0)
	{
		write(2, "./hsh: ", 7);
		write(2, s, _strlen(s));
		write(2, ": exit: Illegal number: ", _strlen(": exit: Illegal number: "));
		write(2, (*args)[1], _strlen((*args)[1]));
		write(2, "\n", 1);
		*st = 2;
		free(s);
		return;
	}
	free(s);
	fre_argv(argv);
	fre(*args);
	free(*input);
	exit(k);
}
