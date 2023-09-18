#include"shell.h"
/**
 * change_dir - change the current directory
 * @path: path of the dir
 * @now: num of line
 * Return: nothing
 */
void change_dir(char **path, int now, char **argv)
{
	char *arg[] = {"pwd", NULL}, buf[1024];
	int i = 0, j = 0, k = 0;

	if ((*path) == NULL)
	{
		char *home = getenv("HOME");

		chdir(home);
		getcwd(buf,sizeof(buf));
		update(argv, buf);
		return;
	}
	char *te = malloc(sizeof(char) * _strlen((*path) + 1));

	k = _strlen((*path));
	if ((*path)[0] == '[')
		i++;
	if ((*path)[_strlen(*path) - 1] == ']')
		k--;
	for (j = 0; i < k; i++)
	{
		te[j] = (*path)[i];
		j++;
	}
	te[j] = '\0';
	if (cmp(*path, "-"))
	{
		chdir("..");
		if (fork() == 0)
			execve("/bin/pwd", arg, environ);
		else
			wait(NULL);
	}
	else if (chdir(te) != 0)
	{
		_puts("sh: ");
		print_int(now);
		_puts("cd: can't cd to ");
		_puts(*path);
		_putchar('\n');
	}
	getcwd(buf,sizeof(buf));
	update(argv, buf);
	free(te);
}
/**
 * update - up
 * @argv: env
 * @value: va
 */
void update(char **argv, char *value)
{
	char *new = malloc(sizeof(char) * (_strlen(value) + 1));
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
		if((s[0] == 'P') && (s[1] == 'W') && (s[2] == 'D'))
		{
			free(argv[i]);
			argv[i] = new;
			return;
		}
	}
	free(new);
}
