#include"shell.h"
/**
 * getpath - get the path for the file
 * @name: name of the file
 * @len: leanth of the name
 * Return: NULL if the file isnot found or the path if the file is found
 */
char *getpath(char *name, int len)
{
	char test1[len + 5];
	char test2[len + 9];
	char *path;
	int i;

	 _strcpy(test1, "/bin/");
	for (i = 5; i <= len + 5; i++)
	{
		test1[i] = name[i - 5];
	}
	if (isfound(test1))
	{
		path = malloc(sizeof(char) * i);
		if (!path)
			return (NULL);
		for (i = 0; test1[i] != '\0'; i++)
			path[i] = test1[i];
		return (path);
	}
	_strcpy(test2, "/usr/bin/");
	for (i = 9; i <= 9 + len; i++)
		test2[i] = name[i - 9];
	if (isfound(test2))
	{
		path = malloc(sizeof(char) * i);
		if (!path)
			return (NULL);
		for (i = 0; test2[i] != '\0'; i++)
			path[i] = test2[i];
		return (path);
	}
	return (NULL);
}
