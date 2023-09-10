#include "shell.h"

/**
 * split - to split the input to command and args
 * @token: command
 * @command: command
 * @args: arguments
 * @arg_count: the args counter
 * Return: void
 */
/*void split(char *input, char *command, char **args)
{
	int arg_count = 1;
	char *token = strtok(input, " ");

	command = token;
	args[0] = command;
	while ((token = strtok(NULL, " ")) != NULL)
	{
		args[arg_count] = token;
		arg_count++;
	}
	args[arg_count] = NULL;
}*/
void split(char *input, char **command, char ***args) {
    int arg_count = 1;
    char *token = strtok(input, " ");

    *command = token;

    // Allocate memory for arguments array
    *args = (char **)malloc(sizeof(char *) * 256);

    if (*args == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    (*args)[0] = *command;

    while ((token = strtok(NULL, " ")) != NULL) {
        (*args)[arg_count] = token;
        arg_count++;
    }

    (*args)[arg_count] = NULL; // Null-terminate the args array
}
