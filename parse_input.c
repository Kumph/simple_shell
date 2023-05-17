#include "main.h"

/**
 * parse_input - parses input by calling strtok then assigning toks to argv
 * @input: user input
 * @args: variable to which we will store tokens as input args
 */
void parse_input(char *input, char **args)
{
	int arg_count = 0;
	char *token;
	token = _strtok(input, " ");

	while(token != NULL && arg_count < MAX_ARGS)
	{
		args[arg_count] = token;
		arg_count++;
		token = _strtok(NULL, " ");
	}
	args = NULL;
}
