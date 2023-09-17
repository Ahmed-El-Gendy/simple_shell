#include "shell.h"

/**
 * comma - to split commands
 * @input: the input
 * Return: void
 */
void comma(char **input)
{
	char *input2, **args, *command;
	int i = 0, j = 0, k = 0;

	for (j = 0; ; j++)
	{
		if ((*input)[j] == ';' || (*input)[j] == '\0')
		{
			if (j == i)
			{
				i = j + 1;
				if ((*input)[j] == '\0')
					break;
				continue;
			}
			input2 = malloc(sizeof(char) *(j - i + 1));
			for (k = 0; i < j; i++, k++)
				input2[k] = (*input)[i];
			input2[k] = '\0';
			split(input2, &command, &args);
			free(input2);
			if (cmp(command, "exit"))
			{
				int k;

				if (!convert(&args, &k))
				{
					fre(command, args);
					free(*input);
					exit(0);
				}
				fre(command, args);
				free(*input);
				exit(k);
			}
			if (con(&command, &args))
			{
				fre(command, args);
				i = j + 1;
				continue;
			}
			else
				 getpath(&command, _strlen(command));
			args[0] = command;
			execute(command, args);
			fre(command, args);
			i = j + 1;
		}
		if ((*input)[j] == '\0')
			break;
	}
}
