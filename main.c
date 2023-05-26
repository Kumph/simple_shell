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

	signal(SIGINT, signal_handler);

	while (1)
	{
		print_prompt();
		tchars_read = getline(&input, &input_len, stdin);
		if (tchars_read == -1)
		{
			free(input);
			input = NULL;
			exit(0);
		}

		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			exit(0);
		}
		if (_strcmp(input, "env") == 0)
		{
			for (i = 0; environ[i] != NULL; i++)
			{
				write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(environ[i]);
			environ = NULL;
		}

		input[_strlen(input) - 1] = '\0';
		parse_input(input, args);
		if (args[0] != NULL)
			execute_command(args);
		for (i = 0; i < MAX_ARGS; i++)
		{
			/*free(args[i]);*/
			args [i] = NULL;
		}
		free(input);
		input = NULL;
	}
	return (0);
}
