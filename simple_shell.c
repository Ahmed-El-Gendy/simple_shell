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
	printf("$ ");
	fflush(stdout);

	/* Read user input using getline */
	if (getline(&input, &len, stdin) == -1)
	{
		break;
	}
	/* remove new line char */
	input[strcspn(input, "\n")] = '\0';

	/* forl a child procces */
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Execute the command using execve */
		char *args[] = {input, NULL};
		char *envp[] = {NULL};
		if (stat(input, &s) != 0)
		{
			printf("No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		execve(input, args, envp);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	/* Free the allocated memory for input */
	free(input);
	input = NULL;
	}

	return (0);
}
