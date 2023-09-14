#include "shell.h"

/**
 * comma - to split commands
 * @input: the input
 * Return: void
 */
void comma(char *input)
{
	char *command = NULL, **args = NULL, *input2 = NULL;
	int i = 0, j = 0, k = 0;

	for (j = 0; ; j++)
	{
		if (input[j] == ';' || input[j] == '\0')
		{
			if (j == i)
			{
				i = j + 1;
				if (input[j] == '\0')
					break;
				continue;
			}
			input2 = malloc(sizeof(char) * (j - i));
			for (k = 0; i < j; i++, k++)
				input2[k] = input[i];
			split(input2, &command, &args);
			free(input2);
			if (cmp(command, "exit"))
			{
				int k;

				if (!convert(&args, &k))
					exit(0);
				exit(k);
			}
			if (con(&command, &args))
			{
				i = j + 1;
				continue;
			}
			else
				command = getpath(command, _strlen(command));
			execute(command, args);
			null_all(&input2, &command, &args);
			i = j + 1;
		}
		if (input[j] == '\0')
			break;
	}
}
