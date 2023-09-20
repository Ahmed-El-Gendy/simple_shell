#include"shell.h"
/**
 * value - value
 * @args: arguments
 * @argv: arg
 */
void value(char **args)
{
	int i, j;
	char *s;

	for (i = 0; environ[i] != NULL; i++)
	{
		s = environ[i];
		if (s[0] =='$')
		{
			char *m = malloc(sizeof(char) * (_strlen(s)));

			for (j = 1; s[j] != '\0'; j++)
				m[j - 1] = s[j];
			m[j - 1] = '\0';
			free(args[i]);
			args[i] = var(m);
			free(m);
		}
	}
}
