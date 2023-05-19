#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_ARGS 10

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void print_prompt(void);
unsigned int delim_c(char c, char *delim);
char *_strtok(char *input_str, char *delim);
void parse_input(char *input, char **args);
/*void execute_command(char *command);*/
void execute_command(char *command, char *arguments[]);

#endif
