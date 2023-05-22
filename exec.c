#include "main.h"
/**
 * execute_command - executes command
 * @args: command
 */

void execute_command(char *args[])
{
	int status;
	pid_t pid;
	char *path = NULL;

	path = get_path(args[0]);
	if (path == NULL)
	{
		perror("Error: command does not exist");
		exit(EXIT_FAILURE);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Error: fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(path, args, NULL);
		perror("Error");
		exit(EXIT_FAILURE);

	}
	else
	{
		waitpid(pid, &status, 0);
	}

}
