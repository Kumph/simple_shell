#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_ARGS 10

char *check_path(char *dir, char *cmd);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void print_prompt(void);
unsigned int delim_c(char c, char *delim);
char *_strtok(char *input_str, char *delim);
void parse_input(char *input, char *args[]);
char *get_path(char *cmd);
void execute_command(char *args[]);
#endif