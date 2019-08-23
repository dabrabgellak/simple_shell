#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

void shell_loop(char **paths);
char *read_line();
char **string_split(char *line, char *delim);
int execute(char *token[], char **paths);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
bool _starts_with(const char *pre, const char *str);
char *_concat(char* str1, char* str2);
#endif
