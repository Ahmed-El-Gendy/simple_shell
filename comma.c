#include "shell.h"

/**
 * comma - to split commands
 * @input: the input
 * @now: num of line
 * Return: void
 */
void comma(char **input, int now)
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
			split(input2, &command, &args, now);
			free(input2);
			if (cmp(command, "exit"))
			{
				if (!convert(&args, &k))
					fro(&command, input, &args, 0);
				fro(&command, input, &args, k);
			}
			if (con(&command, &args, now))
			{
				fre(command, args);
				i = j + 1;
				continue;
			}
			else
				getpath(&command, _strlen(command));
			dish(&command, &args, &i ,j);
		}
		if ((*input)[j] == '\0' || (*input)[j] == '#')
			break;
	}
}

/**
 * dish - to free lines
 * @command: string
 * @args: array
 * Return: void
 */
void dish(char **command, char ***args, int *i, int j)
{
	(*args)[0] = *command;
	execute(*command, *args);
	fre(*command, *args);
	*i = j + 1;
}
/**
 * fro - free
 * @command: string
 * @args: array
 * @input: string
 * Return: void
 */
void fro(char **command, char **input, char ***args, int k)
{
	fre(*command, *args);
	free(*input);
	exit(k);
}
