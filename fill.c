#include "shell.h"
/**
 * fill - fill
 * @argv: env
 * Return: void
 */
void fill(char ***argv)
{
	int i = 0, j = 0;
	char *s, *k;

	for (i = 0; argv[i] != NULL; i++)
	{
		s = (*argv)[i];
		(*argv)[i] = malloc(sizeof(char) * (_strlen(s) + 1));
		k = (*argv)[i];
		for (j = 0; s[j] != '\0'; j++)
			k[j] = s[j];
		k[j] = '\0';
	}
	(*argv)[i] = NULL;
}
/**
 * fre_argv - free
 * @argv: argv
 * Return: void
 */
void fre_argv(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
