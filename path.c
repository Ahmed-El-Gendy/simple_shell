#include"shell.h"
/**
 * getpath - get the path for the file
 * @name: name of the file
 * @len: leanth of the name
 * Return: NULL if the file isnot found or the path if the file is found
 */
char *getpath(char **name, int len)
{
	char test1[len + 5];
	char test2[len + 9];
	int i;
	char *path;

	if (isfound(*name))
		return (*name);
	 _strcpy(test1, "/bin/");
	for (i = 5; i < len + 5; i++)
	{
		test1[i] = (*name)[i - 5];
	}
	test1[i] = '\0';
	if (isfound(test1))
	{
		free(*name);
		*name = malloc(sizeof(char) * i);
		for (i = 0; test1[i] != '\0'; i++)
			(*name)[i] = test1[i];
		(*name)[i] = '\0';
		return (*name);
	}
	_strcpy(test2, "/usr/bin/");
	for (i = 9; i <= 9 + len; i++)
		test2[i] = (*name)[i - 9];
	if (isfound(test2))
	{
		free(*name);
		*name = malloc(sizeof(char ) * i);
		for (i = 0; test2[i] != '\0'; i++)
			path[i] = test2[i];
		path[i] = '\0';
		return (*name);
	}
	return (NULL);
}
