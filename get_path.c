#include "main.h"

/**
 * get_path - searches directories in PATH for cmd's executable file
 * @cmd: command whose executable file to look for in PATH
 * Return: path on sucess or NULL if not found
 */
char *get_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *p;
	char *p2 = NULL;

	p2 = malloc(_strlen(path) + 1);
	if (p2 == NULL)
	{
		perror("Error: unable to allocate memory");
		return (NULL);
	}

	_strcpy(p2, path);
	p = _strtok(p2, ":");

	/*free(p2);*/

	/*iterate through the directories in the path*/
	while (p != NULL)
	{
		char *result = check_path(p, cmd);

		if (result != NULL)
		{
			free(p2);
			return (result);
		}

		p = _strtok(NULL, ":");
	}
	perror("Error:");

	return (NULL);
}
/**
 * check_path - checks the path
 * @dir: parameter
 * @cmd: 2nd parameter
 * Return: returns result
 */
char *check_path(char *dir, char *cmd)
{
	struct stat st;
	char *path_buffer = malloc((_strlen(dir) + _strlen(cmd) + 2) * sizeof(char));

	if (path_buffer == NULL)
	{
		perror("Error: unable to allocate memory");
		return (NULL);
	}

	_strcpy(path_buffer, dir);
	_strcat(path_buffer, "/");
	_strcat(path_buffer, cmd);

	if (stat(path_buffer, &st) == 0 && S_ISREG(st.st_mode))
	{
		char *result = malloc(_strlen(path_buffer) + 1);

		if (result == NULL)
		{
			free(path_buffer);
			return (NULL);
		}
		_strcpy(result, path_buffer);
		free(path_buffer);
		return (result);
	}
	free(path_buffer);
	return (NULL);
}

