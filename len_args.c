#include"shell.h"
/**
 * len_args - The length of arguments
 * @args: array of strings
 * Return: number of elements
 */
int len_args(char ***args)
{
	int i;

	for (i = 0; (*args)[i] != NULL; i++)
		;
	return (i);
}
