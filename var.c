#include"shell.h"
/**
 * var - var
 * @st: string
 * @argv: arg
 * Return: st
 */
char *var(char *st, char **argv)
{
	char *test = malloc(sizeof(char) * (_strlen(st) + 1)), *a, *re;
	int i = 0, j = 0;

	if (!argv)
	{
		free(test);
		return (NULL);
	}
	for (i = 0; argv[i]; i++)
	{
		a = argv[i];
		for (j = 0; a[j] != '\0' && j < _strlen(st); j++)
			test[j] = a[j];
		test[j] = '\0';
		if (cmp(test, st) &&  a[j] == '=')
		{
			free(test);
			re = malloc(sizeof(char) * (_strlen(a) + 1));

			for (i = 0; (a[i] != '=') && (a[i] != '\0'); i++)
				;
			if (a[i] == '\0')
			{
				free(re), free(test);
				return (NULL);
			}
			i++;
			for (j = 0 ; a[i] != '\0'; i++, j++)
				re[j] = a[i];
			re[j] = '\0';
			return (re);
		}
	}
	free(test);
	return (NULL);
}
