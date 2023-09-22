#include"shell.h"
/**
 * change_dir - change the current directory
 * @path: path of the dir
 * @now: num of line
 * @argv: argv
 * @p: p
 * Return: nothing
 */
void change_dir(char **path, int now, char **argv, char *p)
{
	char buf[1024], *arr = var("PWD", argv);
	char *home = var("HOME", argv), *pre = var("OLDPWD", argv);
	char *s = to_st(now), *te;

	p = p;
	if ((*path) == NULL)
	{
		chdir(home);
		getcwd(buf, sizeof(buf));
		oldpwd(argv, arr), update(argv, buf);
		free(pre), free(home), free(arr), free(s);
		return;
	}
	if (cmp(*path, "-"))
	{
		chdir(pre);
		te = var("PWD", argv);
		_puts(te);
		_putchar('\n');
		free(te);
	}
	else if (chdir((*path)) != 0)
	{
		write(2, "./hsh: ", 7), write(2, s, _strlen(s));
		write(2, ": cd: can't cd to ", 18);
		write(2, *path, _strlen(*path)), write(2, "\n", 1);
	}
	getcwd(buf, sizeof(buf));
	oldpwd(argv, arr), update(argv, buf);
	free(home), free(arr), free(pre), free(s);
}
/**
 * update - up
 * @argv: env
 * @value: va
 */
void update(char **argv, char *value)
{
	char *new = malloc(sizeof(char) * (_strlen(value) + 5));
	char *s;
	int i, j;

	new[0] = 'P';
	new[1] = 'W';
	new[2] = 'D';
	new[3] = '=';
	for (i = 4, j = 0; value[j] != '\0'; i++, j++)
		new[i] = value[j];
	new[i] = '\0';
	for (i = 0; argv[i] != NULL; i++)
	{
		s = argv[i];
		if ((s[0] == 'P') && (s[1] == 'W') && (s[2] == 'D'))
		{
			free(argv[i]);
			argv[i] = new;
			return;
		}
	}
	free(new);
}

/**
 * oldpwd - save old pwd
 * @argv: args
 * @value: value
 * Return: void
 */
void oldpwd(char **argv, char *value)
{
	char *new = malloc(sizeof(char) * (_strlen(value) + 8));
	char *s;
	int i, j;

	new[0] = 'O';
	new[1] = 'L';
	new[2] = 'D';
	new[3] = 'P';
	new[4] = 'W';
	new[5] = 'D';
	new[6] = '=';
	for (i = 7, j = 0; value[j] != '\0'; i++, j++)
		new[i] = value[j];
	new[i] = '\0';
	for (i = 0; argv[i] != NULL; i++)
	{
		s = argv[i];
		if ((s[0] == 'O') && (s[1] == 'L') && (s[2] == 'D'))
		{
			if ((s[3] == 'P') && (s[4] == 'W') && (s[5] == 'D'))
			{
				free(argv[i]);
				argv[i] = new;
				return;
			}
		}
	}
	free(new);
}
