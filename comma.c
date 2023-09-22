#include "shell.h"

/**
 * comma - to split commands
 * @input: the input
 * @now: num of linei
 * @argv: argv
 * @st: stat
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
				if ((*input)[j] == '\0')
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
				fre_argv(argv);
				if (!convert(&args, &k))
					fro(&command, input, &args, *st);
				fro(&command, input, &args, k);
			}
			if (con(&command, &args, *now, argv, *input))
			{
				fre(args), i = j + 1;
				continue;
			}
			else
				getpath(&command, _strlen(command), argv, *now);
			*st = d(command, args, &i, j, argv, *now, *input);
			if ((*input)[j] == '#')
				break;
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
 * @argv: argv
 * @n: now
 * @p: p
 * Return: void
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
 * @command: string
 * @args: array
 * @input: string
 * @k: int
 * Return: void
 */
void fro(char **command, char **input, char ***args, int k)
{
	command = command;
	fre(*args);
	free(*input);
	exit(k);
}
