#include "shell.h"

int main()
{
	char *input = NULL;
	size_t len = 0;

	while (true)
	{
	// To be sure you are in the shell
	printf("$ ");
	fflush(stdout);

	// Read user input using getline
	if (getline(&input, &len, stdin) == -1)
	{
		printf("\nExiting the shell.\n");
		break;
	}

	// Print the input and its length
	printf("%s %d\n", input, _strlen(input));

	// Free the allocated memory for input
	free(input);
	input = NULL;
	}

	return 0;
}
