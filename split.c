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
	int arg_count;
	char *token = strtok(input, " ");

	*command = token;
	*args = (char **)malloc(sizeof(char *) * 256);
	(*args)[0] = *command;
	arg_count = 1;
	while ((token = strtok(NULL, " ")) != NULL)
	{
		(*args)[arg_count] = token;
		arg_count++;
	}

	(*args)[arg_count] = NULL;
}
