#include "main.h"

/**
 * main - Simple unix commandline intepreter
 * Return: 0
 */
int main(void)
{
	char *input = NULL;
	ssize_t tchars_read;
	size_t input_len = 0;
	char *args[MAX_ARGS];

	while (1)
	{
		print_prompt();

		tchars_read = getline(&input, &input_len, stdin);

		if (tchars_read == -1)
		{
			perror("Error: unable to read input");
			break;
		}

		input[_strlen(input) - 1] = '\0';

		parse_input(input, args);

		if (args[0] != NULL)
		{
			execute_command(args[0], args);
		}

	}
	free(input);
	return (0);
}
