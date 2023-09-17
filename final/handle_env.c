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
		check[j] = '\0';
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
	}
	(*var)[i] = '\0';
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
		if (findd((*args)[1], (*args)[2]))
		{
			free(var);
			return;
		}
		assign_env(&var, (*args)[1], (*args)[2]);
		for (i = 0; environ[i] != NULL; i++)
			;
		free(environ[i]);
		environ[i] = var;
		environ[i + 1] = NULL;
		return;
	}
	else
		_puts("erorr\n");
}
/**
 * findd - checher variable
 * @st1: string
 * @st2: string
 * Return 1 in sucess 0 in faik
 */
int findd(char *st1, char *st2)
{
	char *s = malloc(sizeof(char) * _strlen(st1));
	char *cl;
	int i, j, c = 0;
	for (i = 0; environ[i] != NULL; i++)
	{
		cl = environ[i];
		for (j = 0; j < _strlen(st1) && cl[j] != '\0'; j++)
			s[j] = cl[j];
		if (cmp(s, st1))
		{
			s[j] = '=';
			j++;
			for (; st2[c] != '\0'; c++,j++)
				s[j] = st2[c];
			free(environ[i]);
			environ[i] = s;
			return (1);
		}
	}
	free(s);
	return (0);
}
