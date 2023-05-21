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
	int i = 0;

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
			execute_command(args);
		}
		for (i = 0; i< MAX_ARGS; i++)
		{
			args[i] = NULL;
		}
		
		free(input);
		input = NULL;

	}
	free(input);
	input = NULL;
	return (0);
}
