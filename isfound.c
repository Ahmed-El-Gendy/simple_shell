#include"shell.h"
/**
 * isfound - is the file found
 * @name: file name
 * Return: 1 if is found 0 if is not found
 */
int isfound(char *name)
{
	struct stat st;

	if (stat(name, &st) == 0)
		return (1);

	return (0);
}
