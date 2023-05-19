#include "main.h"


/**
 * _strcat - function that concatenates two strings
 * @dest: destination of copied
 * @src: source of copied string
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int b, i;

	b = 0;
	i = 0;

	while (dest[b] != '\0')
	{
		b++;
	}


	while (src[i] != '\0')
	{
		dest[b] = src[i];
		b++;
		i++;
	}
	dest[b] = '\0';
	return (dest);
}
