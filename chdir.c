#include"shell.h"
/**
 * change_dir - change the current directory
 * @path: path of the dir
 * Return: nothing
 */
void change_dir(char *path)
{
	if (chdir(path) != 0)
		_puts("no such file or directory\n");
}
