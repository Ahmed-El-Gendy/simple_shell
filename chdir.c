#include"shell.h"
/**
 * change_dir - change the current directory
 * @path: path of the dir
 * Return: nothing
 */
void change_dir(char **path)
{
	if (*path == NULL)
	{
		char *home = getenv("HOME");
		chdir(home);
	}
	else if (cmp(*path, "-"))
		chdir("..");
	else if (chdir(*path) != 0)
		_puts("No such file or directory\n");
}
