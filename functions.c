#include "header.h"

/**
 * read_line - Reads a line.
 * Return: line.
 */

char *read_line()
{
	size_t sizeline = 0;
	char *line;
	size_t chars;

	line = malloc(sizeof(char) * 1024);
	if (line == NULL)
	{
		perror("Unable to allocate tmp");
		exit(1);
	}
	free(line);
	chars = getline(&line, &sizeline, stdin);
	return (line);
}

/**
 * string_split - Separates the lines in tokens.
 * @line: Line that is received.
 * Return: Token.
 */

char *string_split(char *line)
{
	char *token;

	while (token != NULL)
	{
		token = strtok(line, " ");
		if (line != NULL)
		{
			printf("%s", token);
			token = strtok(NULL, " ");
		}
	}
	return (token);
}
