#include "shell.h"
/**
 * cmp - compare between tow strings
 * @input1: first string
 * @input2: second string
 * Return: 1 if they equal 0 if not
 */
int cmp(char *input1, char *input2)
{
	int i;

	if (_strlen(input1) != _strlen(input2))
		return (0);
	for (i = 0; input1[i] != '\0'; i++)
	{
		if (input1[i] != input2[i])
			return (0);
	}
	return (1);
}
