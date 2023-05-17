#include "main.h"

/**
 * main - Simple unix commandline intepreter
 * @argc: argument count
 * @argv: arguments array
 */
int main(int arg_count, char **args)
{
	char *input = NULL;
	size_t input_len = 0;
	ssize_t tchars_read;

	while (1)
	{
		print_prompt ();

		tchars_read = getline(&input, &input_len, stdin);

		if (tchars_read == -1)
		{
			perror("Error: unable to read input\n");
			break;
		}

		parse_input(input, args);

		execute_command(args[0]);

		free(input);
		input = NULL;
		input_len = 0;
	}
	free (input);
}
