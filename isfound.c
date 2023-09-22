#include"shell.h"
/**
 * isfound - to check if the file found
 * @name: file name
 * Return: 1 if is found 0 if isn't found
 */
int isfound(char *name)
{
	struct stat st;

	if (stat(name, &st) == 0)
		return (1);

	return (0);
}
