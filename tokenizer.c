#include "main.h"

/**
 * delim_c - checks whether a char c is a delimeter
 * @c: char
 * @delim: specified delim characters string
 * return: 1 if c is delim char 0 otherwise
 */
unsigned int delim_c(char c, char *delim)
{
	while(*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - tokenizes an input string
 *@input_str: input string to be tokenised
 *@delim: delimeter charcter to use
 *return: the created tokens
 */
char *_strtok(char *input_str, char *delim)
{
	static char *backup_str; /*store starting pt 4 next search*/
	char *ret;

	if (!input_str)
	{
		input_str = backup_str;
	}
	if (!input_str)
	{
		return (NULL);
	}

	while (1)
	{
		if (delim_c(*input_str, delim))
		{
			input_str++;
			continue;
			/*if 1st char is a delim char skip and go to next char*/
		}
		if (*input_str == '\0')
		{
			return (NULL);
		}
		break;
	}

	ret = input_str;
	while (1)
	{
		if (*input_str == '\0')
		{
			backup_str = input_str;
			return (ret);
		}
		if (delim_c(*input_str, delim))
		{
			*input_str = '\0';
			backup_str = input_str + 1;
			return (ret);
		}
		input_str++;
	}
}

