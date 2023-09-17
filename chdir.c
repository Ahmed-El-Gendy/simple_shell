#include"shell.h"
/**
 * change_dir - change the current directory
 * @path: path of the dir
 * Return: nothing
 */
void change_dir(char **path)
{
	char* argv[] = {"pwd", NULL};
	int i, j, k;

	if ((*path) == NULL)
	{
		char *home = getenv("HOME");

		chdir(home);
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
	if (cmp(*path, "-"))
	{
		chdir("..");
		if( fork() == 0)
			execve("/bin/pwd", argv, environ);
		else
			wait(NULL);
	}
	else if (chdir(te) != 0)
		_puts("No such file or directory\n");
	free(te);
}
