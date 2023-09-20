#include"shell.h"
/**
 * convert - convert string to int
 * @args: array of string
 * @res: int
 * Return: int
 */
int convert(char ***args, int *res)
{
	char *st = (*args)[1];
	int i = 0, j = 0;

	*res = 0;
	if (st == NULL)
		return (0);
	if (st[0] == '-')
		j = 1;
	for (i = 0; st[i] != '\0'; i++)
	{
		if (st[i] == '-')
			continue;
		*res += st[i] - '0';
		*res *= 10;
	}
	*res /= 10;
	if (j)
		(*res) *= -1;
	return (1);
}
