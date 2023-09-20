#include "shell.h"

/**
* null_all - null all elements
* @input: string
* @command: string
* @args: array of arguments
* Return: void
*/

void null_all(char **input, char **command, char ***args)
{
	*input = NULL;
	*command = NULL;
	**args = NULL;
}
