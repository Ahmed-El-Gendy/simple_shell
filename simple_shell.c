#include "shell.h"
/**
 * main - The main function of our project
 * Return: always 0
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	struct stat s;

	while (true)
	{
	/* To be sure you are in the shell */
	_puts("Saged$ ");
	fflush(stdout);
	/* Read user input using getline */
	if (getline(&input, &len, stdin) == -1)
		break;
	/* Skip processing if the input is empty */
	if (strlen(input) == 0)
		continue;
	/* remove new line char */
	input[strcspn(input, "\n")] = '\0';
	/* Execute the command using execve */
	char *token = strtok(input, " ");
	char *command = token;
	char *args[256] = {command};
	int arg_count = 1;

	while ((token = strtok(NULL, " ")) != NULL)
	{
		args[arg_count] = token;
		arg_count++;
	}
	args[arg_count] = NULL;

	if (!getpath(command, _strlen(command)))
	{
		printf("No such file or directory\n");
		continue;
	}
	else
	{
		command = getpath(command, _strlen(command));
	}

	/* forl a child procces */
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command, args, environ);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);


	/* Free the allocated memory for input */
	free(input);
	input = NULL;
	}

	return (0);
}
