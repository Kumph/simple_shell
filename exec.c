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

	if (_strcmp(args[0], "cd") == 0)
	{
		if (builtin_cd(args[1]) != 0)
		{
			write(STDERR_FILENO, "cd: Failed to change directory\n", 31);
		}
		return;
	}
	path = get_path(args[0]);
	if (path == NULL)
	{
		perror("Error: command not found");
		write(STDERR_FILENO, "cd: Failed to change directory\n", 31);
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Error: fork failed");
		exit(EXIT_SUCCESS);
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
	free(path);

}
