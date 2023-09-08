#include"shell.h"
/**
 * split - split string
 * @string: s
 * Return: array of strings
 */
char **split(char *string, size_t len)
{
	char *s[len];
	char *p;
	size_t i, cnt = 0, j = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == ' ')
		{
			s[cnt] = p;
			cnt++;
			free(p);
			j = 0;
		}
		else
		{
			p[j] = string[i];
			j++;
		}
	}
	return (s);
}
