#include "main.h"

/**
 * get_path - searches directories in PATH for cmd's executable file
 * @cmd: command whose executable file to look for in PATH
 * Return: path on sucess or NULL if not found
 */
char *get_path(char *cmd)
{
	char *path = getenv("PATH");
	char *p;
	struct stat st;
	p = _strtok(path, ":");

	/*iterate through the directories in the path*/
	while (p != NULL)
	{
		char path_buffer[_strlen(p) + _strlen(cmd) + 2];
		_strcpy(path_buffer, p);
		_strcat(path_buffer, "/");
		_strcat(path_buffer, cmd);

		/*checking if the cmd file exists and is a regular file*/
		if (stat(path_buffer, &st) == 0 && S_ISREG(st.st_mode))
		{
			char *result = malloc(_strlen(path_buffer) + 1);
			if (result == NULL)
			{
				return (NULL);
			}
			strcpy(result, path_buffer);
			return (result);
		}

		p = _strtok(NULL, ":");
	}
	perror ("Error:");
	return (NULL);
}
