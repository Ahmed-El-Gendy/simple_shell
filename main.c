#include"shell.h"
int main()
{
	char name[] = "ls";
	if (getpath(name, _strlen(name)) != NULL)
	printf("%s\n", getpath(name, _strlen(name)));
	else
		printf("not found\n");
	return (0);
}
