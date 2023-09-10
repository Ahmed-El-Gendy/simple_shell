#include "shell.h"

/**
 * handle_echo - handle echo case
 * @input: string
 * @args: arguments
 * Return: 1 or 0
 */

int handle_echo(char *input, char **command, char ***args)
{
	int arg_count, i, co = 0, j, le, k;
	char *token = NULL, is;

	for (i = 0; input[i] == ' '; i++);
	for (co = i; input[co] != ' ' && input[co] != '\0'; co++);
	/*token = malloc(sizeof(char) * co);
	for (j = 0; i < co; i++, j++)
		token[j] = input[i];
	*command = token;*/
	*args = (char **)malloc(sizeof(char *) * 2);
	(*args)[0] = *command;
	for (i = co; input[i] == ' ' && input[i] != '\0'; i++);
	if (input[i] == '\0')
		return (1);
	is = input[i];
	if (is == '\'' || is == '\"')
	{
		le = _strlen(input);
		for (le = le - 1; input[le] == ' '; le--);
		if (le == i)
			return (1);
		if (input[le] == is)
		{
			char *st = malloc(sizeof(char) * (le - i - 1));

			for (j = i + 1, k = 0; j < le; j++, k++)
				st[k] = input[j];
			(*args)[1] = st;
			return (0);
		}
		else
			return (1);
	}
	else
		return (1);
}
