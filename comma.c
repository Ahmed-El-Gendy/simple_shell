#include "shell.h"

/**
 * comma - to split commands
 * @input: the input
 * @now: num of line
 * Return: void
 */
int comma(char **input, int now)
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
			split(input2, &command, &args);
			value(args);
			free(input2);
			if (cmp(command, "exit"))
			{
				if (!convert(&args, &k))
				{
					fre(args);
					return (0);
					fro(&command, input, &args, 0);
				}
				fro(&command, input, &args, k);
				i = j + 1;
				continue;
			}
			if (con(&command, &args, now))
			{
				fre(args);
				i = j + 1;
				continue;
			}
			else
				getpath(&command, _strlen(command));
			dish(&command, &args, &i, j, now);
		}
		if ((*input)[j] == '\0' || (*input)[j] == '#')
			break;
	}
	return (1);
}

/**
 * dish - to free lines
 * @command: string
 * @args: array
 * @i: int
 * @j: int
 * Return: void
 */
void dish(char **command, char ***args, int *i, int j, int now)
{
	(*args)[0] = *command;
	execute(*command, *args, now);
	fre(*args);
	*i = j + 1;
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
	if (k < 0)
	{
		write(2, "./hsh: exit: Illegal number: ", 29);
		write(2, (*args)[1], _strlen((*args)[1]));
		write(2, "\n", 1);
		return;
	}
	fre(*args);
	free(*input);
	exit(k);
}
