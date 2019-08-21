#include "header.h"

#define DELIM " "

/**
 * read_line - Reads a line.
 * Return: line.
 */

char *read_line()
{
	size_t sizeline = 0;
	char *line;

	line = malloc(sizeof(char) * 1024);
	if (line == NULL)
	{
		perror("Unable to allocate line");
		exit(1);
	}
	free(line);

	if (line != NULL)
	{
		getline(&line, &sizeline, stdin);
	}
	return (line);
}

/**
 * string_split - Separates the lines in tokens.
 * @line: Line that is received.
 * Return: Token.
 */

char *string_split(char *line)
{
	char *token = 0;

	while (token != NULL)
	{
		token = strtok(line, DELIM);
		if (line != NULL)
		{
			printf("%s", token);
			token = strtok(NULL, DELIM);
		}
	}
	return (token);
}

/**
 * execute - Executes.
 * @args: All arguments.
 * Return: .
 */

int execute(char *args)
{
	pid_t parent_id;
	int status;

	parent_id = fork();
	if (parent_id == 0)
	{
		if (execve(PATH, args[1]) == -1)
		{
			return (-1);
		}
	}
	else
	{
		waitpid(parent_id, status, 0);
	}
	return (status);
}
