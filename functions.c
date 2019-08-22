#include "header.h"
#define DELIM " "

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

char **string_split(char *line)
{
	int len = 0;
	char **token;

	token = malloc(sizeof(char *) * 1024);
		token[0] = strtok(line, DELIM);
		while (token[len] != NULL)
		{
			len++;
			token[len] = strtok(NULL, DELIM);
			printf("%s\n", token[0]);
		}
		token[len] = NULL;
	return (token);
}

/**
 * execute - Executes.
 * @args: All arguments.
 * Return: .
 */

int execute(char *token[])
{
	pid_t parent_id;
	pid_t child_status;

	parent_id = fork();
	if (parent_id == 0)
	{
		if (execve(token[0], token, NULL) == -1)
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
