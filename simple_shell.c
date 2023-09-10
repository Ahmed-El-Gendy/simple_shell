#include "shell.h"
/**
 * main - The main function of our project
 *
 * Return: always 0
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	struct stat s;
	int check = isatty(STDIN_FILENO);

	while (true)
	{
	if (check)
		_puts("saged$ ");
	fflush(stdout);
	if (getline(&input, &len, stdin) == -1)
		break;
	input[strcspn(input, "\n")] = '\0';
	if (_strlen(input) == 0)
		continue;
	if (cmp(input, "exit"))
		break;
	char *command = NULL, **args = NULL;

	split(input, &command, &args);
	if (con(command, args[1]))
		continue;
	else
		command = getpath(command, _strlen(command));
	if (fork() == 0)
		execve(command, args, environ);
	else
		wait(NULL);
	input = NULL;
	command = NULL;
	}
	free(input);
	return (0);
}
