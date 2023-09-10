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
	while ((token = strtok(NULL, " ")) != NULL)
	{
		args[arg_count] = token;
		arg_count++;
	}
	args[arg_count] = NULL;
	if (cmp(command, "cd"))
	{
		change_dir(args[1]);
		continue;
	}
	if (!getpath(command, _strlen(command)))
	{
		_puts("No such file or directory\n");
		continue;
	}
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
