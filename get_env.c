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
		if (_strncmp(name, *env, length) == 0 && (*env)[length] == '=')
		{
			return (env + length + 1);
		}
		env++;
	}
	return (NULL);
}

