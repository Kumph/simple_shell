#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_ARGS 10

void print_prompt(void);
unsigned int delim_c(char c, char *delim);
char *_strtok(char *input_str, char *delim);
void parse_input(char *input, char **args);


#endif
