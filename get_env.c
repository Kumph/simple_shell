#include "main.h"
char *_getenv(const char *name)
{
	int length = _strlen(name);
	char **env = environ;

	if (name == NULL)
	{
		return (NULL);
	}

	while (*env != NULL)
	{
		if (_strcmp(name, *env) == 0 && (*env)[length] == '=')
		{
			return (*env + length + 1);
		}
		env++;
	}
	return (NULL);
}

