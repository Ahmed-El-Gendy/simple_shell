#include "shell.h"

/**
 * handle_echo - handle echo case
 * @input: string
 * @command: command
 * @args: arguments
 * Return: 1 or 0
 */

int handle_echo(char *input, char *command, char ***args)
{
	int i = 0, co = 0, j = 0, le, k;
	char is, *st;

	fors(&i, &co, input);
	*args = (char **)malloc(sizeof(char *) * 2);
	(*args)[0] = command;
	is = input[i];
	if (input[i] == '\0' || (is != '\'' && is != '\"'))
	{
		fre1(*args);
		return (1);
	}
	le = _strlen(input);
	for (le = le - 1; input[le] == ' '; le--)
		;
	if (le == i)
	{
		fre1(*args);
		return (1);
	}
	if ((input[le] == is) && (is == '\'' || is == '\"'))
	{
		(*args)[1] = malloc(sizeof(char) * (le - i - 1));
		st = (*args)[1];

		for (j = i + 1, k = 0; j < le; j++, k++)
			st[k] = input[j];
		st[k] = '\0';
		(*args)[1] = st;
		st = NULL;
		free(st);
		return (0);
	}
	else
	{
		fre1(*args);
		return (1);
	}
}

/**
 * fre1 - free
 * @args: args
 */

void fre1(char **args)
{
	args[0] = NULL;
	free(args[0]);
	free(args[1]);
	free(args);
}

/**
 * fors - for loop
 * @i: int
 * @co: int
 * @input: array
 */
void fors(int *i, int *co, char *input)
{
	for (*i = 0; input[*i] == ' '; (*i)++)
		;
	for (*co = *i; input[*co] != ' ' && input[(*co)] != '\0'; (*co)++)
		;
	for (*i = *co; input[*i] == ' ' && input[(*i)] != '\0'; (*i)++)
		;
}
