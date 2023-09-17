#include "shell.h"
/**
 * unset_env - unset
 * @var: var
 */
void unset_env(char *var)
{
	int i, j, k = _strlen(var), c = 0;
	char *check = malloc(sizeof(char) * (k + 1)), *or;

	for (i = 0; environ[i] != NULL; i++)
	{
		or = environ[i];
		for (j = 0; j < k && or[j] != '\0'; j++)
			check[j] = or[j];
		if (cmp(check, var))
		{
			c = 1;
			break;
		}
	}
	if (c)
	{
		for (i = i; environ[i] != NULL; i++)
			environ[i] = environ[i + 1];
	}
	else
	{
		_puts("not found\n");
	}
	free(check);
	return;
}

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
	int i;

	if (n == 1)
		_puts("erorr\n");
	else if (n == 2)
	{
		if (cmp(*command, "setenv"))
		{
			_puts("erorr\n");
			return;
		}
		unset_env((*args)[1]);
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
		for (i = 0; environ[i] != NULL; i++)
			;
		environ[i] = var;
		environ[i + 1] = NULL;
		var = NULL;
		free(var);
		return;
	}
	else
		_puts("erorr\n");
}
