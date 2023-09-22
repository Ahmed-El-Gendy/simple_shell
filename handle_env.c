#include "shell.h"
/**
 * unset_env - unset
 * @var: var
 * @argv: argv
 */
void unset_env(char *var, char **argv)
{
	int i, j, k = _strlen(var), c = 0;
	char *or;

	for (i = 0; argv[i] != NULL; i++)
	{
		char *check = malloc(sizeof(char) * (k + 1));

		or = argv[i];
		for (j = 0; j < k && or[j] != '\0'; j++)
			check[j] = or[j];
		check[j] = '\0';
		if (cmp(check, var))
		{
			c = 1;
			free(check);
			break;
		}
		free(check);
	}
	if (c)
	{
		for (i = i; argv[i] != NULL; i++)
		{
			free(argv[i]);
			argv[i] = argv[i + 1];
		}
		free(argv[i]);
	}
	else
	{
		write(2, "not found\n", 10);
	}
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
 * @argv: argv
 * @command: command
 * @now: now
 */
void handle_env(char **command, char ***args, int n, char **argv, int now)
{
	char *var;
	int i;

	if (n == 1)
		pr_error(*command, now);
	else if (n == 2)
	{
		if (cmp(*command, "setenv"))
		{
			pr_error(*command, now);
			return;
		}
		unset_env((*args)[1], argv);
		return;
	}
	else if (n == 3)
	{
		if (cmp(*command, "usetenv"))
		{
			pr_error(*command, now);
			return;
		}
		var = malloc(sizeof(char) * (_strlen((*args)[1]) + _strlen((*args)[2]) + 2));
		if (findd((*args)[1], (*args)[2], argv))
		{
			free(var);
			return;
		}
		assign_env(&var, (*args)[1], (*args)[2]);
		for (i = 0; argv[i] != NULL; i++)
			;
		free(argv[i]);
		argv[i] = var;
		argv[i + 1] = NULL;
		return;
	}
	else
		pr_error(*command, now);
}

/**
 * findd - checher variable
 * @st1: string
 * @st2: string
 * @argv: argv
 * Return: 1 in sucess 0 in faik
 */

int findd(char *st1, char *st2, char **argv)
{
	char *s = malloc(sizeof(char) * (_strlen(st1) + 2 + _strlen(st2)));
	char *cl;
	int i, j, c = 0;

	if (s == NULL)
		return (0);
	for (i = 0; argv[i] != NULL; i++)
	{
		cl = argv[i];
		for (j = 0; j < _strlen(st1) && cl[j] != '\0'; j++)
			s[j] = cl[j];
		s[j] = '\0';
		if (cmp(s, st1))
		{
			s[j] = '=';
			j++;
			for (; st2[c] != '\0'; c++, j++)
				s[j] = st2[c];
			free(argv[i]);
			argv[i] = s;
			argv[i + 1] = NULL;
			return (1);
		}
	}
	free(s);
	return (0);
}
