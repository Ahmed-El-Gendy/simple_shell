#include"shell.h"
/**
 * getpath - get the path for the file
 * @name: name of the file
 * @len: leanth of the name
 * Return: NULL if the file isnot found or the path if the file is found
 */
char *getpath(char **name, int len)
{
	int i, j, k;
	char *token, *st, *t;

	len = len;
	if (isfound(*name))
		return (*name);
	token = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	j = 0;
	for (i = 0; ; i++)
	{
		if (token[i] == ':' || token[i] == '\0')
		{
			st = malloc(sizeof(char) * (i-j) + 1);
			for (k = 0; j < i; j++, k++)
			{
				st[k] = token[j];
			}
			st[k] = '\0';
			t = malloc(sizeof(char) * (_strlen(st) + _strlen(*name)) + 2);
			for (k = 0; k < _strlen(st); k++)
			{
				t[k] = st[k];
			}
			t[k] = '/';
			k++;
			for (j = 0; j < _strlen(*name); j++, k++)
			{
				t[k] = (*name)[j];
			}
			t[k] = '\0';
			if (isfound(t))
			{
				free(st);
				free(*name);
				*name = t;
				return (*name);
			}
			free(st), free(t);
			j = i + 1;
		}
		if (token[i] == '\0')
			break;
	}
	return (NULL);
}
