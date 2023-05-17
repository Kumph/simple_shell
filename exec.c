#include "main.h"
/**
 * execute_command - executes command
 * @command: command
 */

void execute_command(char *command)
{
	int status;
	pid_t pid = fork();
	char *arguments[3];

	arguments[0] = command;
	arguments[1] = NULL;

	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command, arguments, NULL);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

