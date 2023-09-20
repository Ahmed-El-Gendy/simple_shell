#include"shell.h"
/**
 * tost - to int
 * @now: now
 * Return: st
 */
char *tost(int now)
{
	char *st, *str;
	int i = 0, j;

	st = malloc(sizeof(char) * 20);
	while (now != 0)
	{
		st[i] = (now % 10) + '0';
		i++;
		now /= 10;
	}
	st[i] = '\0';
	str = malloc(sizeof(char) * (_strlen(st) + 1));
	for (i = 0, j = _strlen(st) - 1; j >= 0; i++, j--)
		str[i] = st[j];
	str[i] = '\0';
	free(st);
	return (str);
}
