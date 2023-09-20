#include "shell.h"

/**
 * split - to split the input to command and args
 * @input: command
 * @command: command
 * @args: arguments
 * @now: num of line
 * Return: void
 */
void split(char *input, char **command, char ***args, int now)
{
	int arg_count, i = 0, co = 0, j;
	char *token2;

	now = now;
	for (i = 0; input[i] == ' '; i++)
		;
	for (co = i; (input[co] != ' ') && (input[co] != '\0'); co++)
		;
	 *command = malloc(sizeof(char) * (co - i + 1));

	for (j = 0; i < co; i++, j++)
		(*command)[j] = input[i];
	 (*command)[j] = '\0';

	if (cmp(*command, "echo"))
	{
		if (!handle_echo(input, *command, args))
			return;
	}
	*args = (char **)malloc(sizeof(char *) * 256)
		;
	(*args)[0] = *command;
	arg_count = 1;
	while (input[co] != '\0')
	{
		while (input[co] == ' ' && input[co] != '\0')
			co++;
		if (input[co] == '\0')
			break;
		for (i = 0; input[i + co] != ' ' && input[i + co] != '\0'; i++)
			;
		(*args)[arg_count] = malloc(sizeof(char) * i);
		token2 = (*args)[arg_count];

		for (j = 0; input[co] != ' ' && input[co] != '\0'; co++, j++)
			token2[j] = input[co];
		token2[j] = '\0';
		(*args)[arg_count] = token2;
		arg_count++;
	}
	(*args)[arg_count] = NULL;
}
