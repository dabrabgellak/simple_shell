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

void shell_loop(void);
char *read_line();
char **string_split(char *line);
int execute(char *token[]);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
#endif
