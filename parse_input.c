#include "main.h"

/**
 * parse_input - parses input by calling strtok then assigning toks to argv
 * @input: user input
 * @args: variable to which we will store tokens as input args
 */
void parse_input(char *input, char *args[])
{
	int arg_count = 0;
	char *token;
	size_t input_len;

	input_len = _strlen(input);
	if (input_len > 0 && input[input_len - 1] == '\n')
	{
		input[input_len - 1] = '\0';
	}

	token = strtok(input, " ");

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

}
