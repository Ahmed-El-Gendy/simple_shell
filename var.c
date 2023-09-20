#include"shell.h"
/**
 * var - var
 * @st: string
 * Return: st
 */
char *var(char *st, char **argv)
{
	char *test = malloc(sizeof(char) * (_strlen(st) + 1)), *a;
	int i = 0, j = 0;

	for (i = 0; argv[i] != NULL; i++)
	{
		a = argv[i];
		for (j = 0; a[j] != '\0' && j < _strlen(st); j++)
			test[j] = a[j];
		test[j] = '\0';
		if (cmp(test, st))
		{
			free(test);
			char *re = malloc(sizeof(char) * (_strlen(a) + 1));

			for (i = 0; a[i] != '='; i++)
				;
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
