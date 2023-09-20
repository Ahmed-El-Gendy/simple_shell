#include"shell.h"
/**
 * value - value
 * @args: arguments
 * @argv: arg
 */
void value(char **args, char **argv)
{
	int i, j;
	char *s, v;

	for (i = 0; args[i] != NULL; i++)
	{
		s = args[i];
		if (s[0] =='$')
		{
			char *m = malloc(sizeof(char) * (_strlen(s)));

			for (j = 1; s[j] != '\0'; j++)
				m[j - 1] = s[j];
			m[j - 1] = '\0';
			free(args[i]);
			args[i] = var(m, argv);
			free(m);
		}
	}
}
