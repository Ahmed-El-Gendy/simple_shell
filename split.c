#include "shell.h"

/**
 * split - to split the input to command and args
 * @input: command
 * @command: command
 * @args: arguments
 * Return: void
 */
void split(char *input, char **command, char ***args)
{
	int arg_count, i, co = 0, j;
	char *token = NULL;

	for (i = 0; input[i] == ' '; i++);
	for (co = i; input[co] != ' ' && input[co] != '\0'; co++);
	token = malloc(sizeof(char) * co);
	for (j = 0; i < co; i++, j++)
	{
		token[j] = input[i];
	}

	*command = token;
	if (cmp(input, "echo"))
	{
		handle_echo(input, args);
		return;
	}
	*args = (char **)malloc(sizeof(char *) * 256);
	(*args)[0] = *command;
	arg_count = 1;
	while (input[co] != '\0')
	{
		while (input[co] == ' ' && input[co] != '\0')
			co++;
		if (input[co] == '\0')
				break;
		for (i = 0; input[i + co] != ' ' && input[i + co] != '\0'; i++);
		token = NULL;
		token = malloc(sizeof(char) * i);
		for (j = 0; input[co] != ' ' && input[co] != '\0'; co++, j++)
			token[j] = input[co];
		(*args)[arg_count] = token;
		arg_count++;
	}

	(*args)[arg_count] = NULL;
}
