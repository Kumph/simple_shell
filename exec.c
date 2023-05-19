#include "main.h"
/**
 * execute_command - executes command
 * @command: command
 */

void execute_command(char *cmd, char *arguments[])
{
	int status;
	pid_t pid = fork();
	char *path = NULL;
	
	arguments[0] = cmd;
	arguments[1] = NULL;

	path = get_path(cmd);

	if (pid == -1)
	{
		perror("Error: fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(path, arguments, NULL);
		perror("Error");
		exit(EXIT_FAILURE);

	}
	else
	{
		waitpid(pid, &status, 0);
	}

}
