#include "main.h"

/**
 * get_path - searches directories in PATH for cmd's executable file
 * @cmd: command whose executable file to look for in PATH
 * Return: path on success or NULL if not found
 */
char *get_path(char *cmd)
{
	char *path_buffer;
	char *path = _getenv("PATH");
	char *p = strtok(path, ":");
	char *result = NULL;
	struct stat st;

	while (p != NULL)
	{
		path_buffer = malloc((_strlen(p) + _strlen(cmd) + 2) * sizeof(char));
		if (path_buffer == NULL)
		{
			perror("Error: unable to allocate memory");
			free(path);
			return NULL;
		}

		strcpy(path_buffer, p);
		_strcat(path_buffer, "/");
		_strcat(path_buffer, cmd);

		if (stat(path_buffer, &st) == 0 && S_ISREG(st.st_mode))
		{
			result = malloc(_strlen(path_buffer) + 1);
			if (result == NULL)
			{
				perror("Error: unable to allocate memory");
				free(path_buffer);
				free(path);
				return NULL;
			}

			_strcpy(result, path_buffer);
			break;
		}

		p = strtok(NULL, ":");
		free(path_buffer);
	}
	free(path_buffer);
	free(path);
	return (result);
}
