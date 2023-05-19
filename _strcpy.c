#include "main.h"

/**
 * _strcpy - copies string pointed to by src including \0 to dest
 * @dest: destination of copied string
 * @src: source of string to be copied
 * Return: char
 */
char *_strcpy(char *dest, char *src)
{
	char *begn = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (begn);
}
