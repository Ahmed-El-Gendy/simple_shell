#include "shell.h"
/**
 * assign_env - assign
 * @var: var
 * @s1: s1
 * @s2: s2
 */
void assign_env(char **var, char *s1, char *s2)
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		(*var)[i] = s1[i];
	(*var)[i] = '=';
	i++;
	if (s2)
	{
		for (j = 0; s2[j] != '\0'; j++)
		{
			(*var)[i] = s2[j];
			i++;
		}
		(*var)[i] = '\0';
	}
}
		
/**
 * handle_env - setenv or unsetenv
 * @args: arguments
 * @n: number of element
 * @command: command
 */
void handle_env(char **command, char ***args, int n)
{
	char *var;

	if (n == 1)
		_puts("erorr\n");
	else if (n == 2)
	{
		if (cmp(*command, "setenv"))
		{
			_puts("erorr\n");
			return;
		}
		char *en = getenv((*args)[1]);

		if (en == NULL)
			_puts("erorr\n");
		else
		{
			var = malloc(sizeof(char) * (_strlen((*args)[1]) + 2));
			assign_env(&var, (*args)[1], NULL);
			putenv(var);
		}
		return;
	}
	else if (n == 3)
	{
		if (cmp(*command, "usetenv"))
		{
			_puts("erorr\n");
			return;
		}
		var = malloc(sizeof(char) * (_strlen((*args)[1]) + _strlen((*args)[2]) + 2));
		assign_env(&var, (*args)[1], (*args)[2]);
		putenv(var);
		return;
	}
	else
		_puts("erorr\n");
}
