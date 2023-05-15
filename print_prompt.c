#include "main.h"
/**
 * print_prompt - prints the prompt to the terminal
 */
void print_prompt(void)
{
	char *prompt = "s_shell$ ";
	int prompt_len = 9;

	write(STDOUT_FILENO, prompt, prompt_len);
	fflush(stdout);
}
