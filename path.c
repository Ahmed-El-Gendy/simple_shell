#include"shell.h"
/**
 * getpath - Get the path for the file
 * @name: Name of the file
 * @len: The leanth of the name
 * @argv: environ
 * @now: now
 * Return: NULL if the file isn't found or the path if the file is found
 */
char *getpath(char **name, int len, char **argv, int now)
{
	int i, j, k;
	char *token, *st, *t;

	argv = argv, len = len, now = now;
	if (isfound(*name))
		return (*name);
	token = var("PATH", argv), j = 0;
	if (token == NULL)
		return (NULL);

	for (i = 0; token[i]; i++)
	{
		if (token[i] == ':' || token[i] == '\0')
		{
			st = malloc(sizeof(char) * (i - j) + 1);
			for (k = 0; j < i; j++, k++)
			{
				st[k] = token[j];
			}
			st[k] = '\0';
			t = malloc(sizeof(char) * (_strlen(st) + _strlen(*name)) + 2);
			for (k = 0; k < _strlen(st); k++)
				t[k] = st[k];
			t[k] = '/', k++;
			for (j = 0; j < _strlen(*name); j++, k++)
				t[k] = (*name)[j];
			t[k] = '\0';
			if (isfound(t))
			{
				free(st), free(*name), free(token), *name = t;
				return (*name);
			}
			free(st), free(t), j = i + 1;
		}
		if (token[i] == '\0')
			break;
	}
	free(token);
	return (NULL);
}
