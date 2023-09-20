#include "shell.h"
/**
 * rep - remove the "\n"
 * @input: the input
 * Return: 1 if true 0 if false
 */
int rep(char *input)
{
	int i;

	for (i = 0; input[i] != '\n'; i++)
		;
	if (_strlen(input) == 0)
		return (1);
	return (0);
}
