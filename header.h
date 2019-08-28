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

void shell_loop(char **paths, char *env[], bool interactive);
char *read_line();
char **string_split(char *line, char *delim);
int execute(char *token[], char **paths, char *env[]);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
bool _starts_with(const char *pre, const char *str);
char *_concat(const char *str1, const char *str2);
void env_builtin(char *env[]);

#endif
