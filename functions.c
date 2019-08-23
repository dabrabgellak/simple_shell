#include "header.h"
#include <unistd.h>

/**
 * read_line - Reads a line.
 * Return: line.
 */

char *read_line()
{
	size_t sizeline = 1024;
	char *line;

	line = malloc(sizeof(char) * sizeline);
	if (line == NULL)
	{
		perror("Unable to allocate line");
		exit(1);
	}

		if (getline(&line, &sizeline, stdin) == EOF)
			exit(0);

	line[strlen(line) - 1] = '\0';

	return (line);
}

/**
 * string_split - Separates the lines in tokens.
 * @line: Line that is received.
 * Return: Token.
 */

char **string_split(char *line, char *delim)
{
	int len = 0;
	char **token;

	token = malloc(sizeof(char *) * 1024);
		token[0] = strtok(line, delim);
		while (token[len] != NULL)
		{
			len++;
			token[len] = strtok(NULL, delim);
//			printf("%s\n", token[0]);
		}
		token[len] = NULL;
	return (token);
}

// command is the command typed in the shell, without arguments
// if the command is an absolute path (starts with "/"), returns command
// otherwise, checks if a file named command exists in any of the $PATH directories
// as soon as such a file is found, returns the absolute path to it.
char *get_exec_path(char *command, char **paths) {
    int i;
    char* result;
    char* tmp;
    if (command == NULL) {
        return NULL;
    }
    if (command[0] == '/') {
        if (access(command, X_OK) == -1) {
            return NULL;
        }
        return command;
    }
    for (i = 0; paths[i] != NULL; i++) {
        tmp = _concat(paths[i], "/");
        result = _concat(tmp, command);
        free(tmp);
        if (access(result, X_OK) == -1) {
            free(result);
            continue;
        }
        return result;
    }
    return NULL;
}

/**
 * execute - Executes.
 * @args: All arguments.
 * Return: .
 */

int execute(char *token[], char **paths)
{
	pid_t parent_id;
	pid_t child_status;
	char* exec_path;

	parent_id = fork();
	if (parent_id == 0)
	{
	    exec_path = get_exec_path(token[0], paths);

		//if (execve(token[0], token, NULL) == -1)
		if (exec_path == NULL || execve(token[0] = exec_path, token, NULL) == -1)
		{
			perror("NO EXISTO");
			exit(0);
		}
	}
	else
	{
		wait(&child_status);
	}
	return (1);
}
