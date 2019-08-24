#include "header.h"
#include <unistd.h>

/**
 * read_line - Reads a line.
 * Return: line.
 */

char *read_line()
{
	size_t sizeline = 1024;
	char *line = NULL;

	/*line = malloc(sizeof(char) * sizeline);
	if (line == NULL)
	{
		perror("Unable to allocate line");
		exit(1);*/
	

	if (getline(&line, &sizeline, stdin) == EOF)
	{	
		exit(0);
	}

	line[strlen(line) - 1] = '\0';

	return (line);
}

/**
 * free_grid - frees a 2D grid
 * @token: grid
 * Return: nothing
 */
void free_grid(char **token)
{
    int i;

	for (i = 0; token[i] != NULL; i++)
	{
		free(token[i]);
	}
	free(token);
}

/**
 * string_split - Separates the lines in tokens.
 * @line: Line that is received.
 * @delim: Delimeter that separates the tokens.
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
			/**printf("%s\n", token[0]);*/
		}
		token[len] = NULL;
	return (token);
}

/**
 * get_exec_path - returns the absolte path to execute a given
 * command taking $PATH into consideration
 * @command: an executable
 * @paths: an array of paths where to check for an executable
 * Return: absolute path to execute a given command
 */


char *get_exec_path(char *command, char **paths)
{
	int i;
	char *result;
	char *tmp;

	if (command == NULL)
	{
		return (NULL);
	}
	if (command[0] == '/')
	{
		if (access(command, X_OK) == -1)
		{
			return (NULL);
		}
		return (command);
	}
	for (i = 0; paths[i] != NULL; i++)
	{
		tmp = _concat(paths[i], "/");
		result = _concat(tmp, command);
		free(tmp);
		if (access(result, X_OK) == -1)
		{
			free(result);
			continue;
		}
		return (result);
	}
	return (NULL);
}

/**
 * execute - Executes.
 * @token: All arguments.
 * @paths: All the paths from $PATH environment variable.
 * Return: .
 */

int execute(char *token[], char **paths)
{
	pid_t parent_id;
	pid_t child_status;
	char *exec_path;

	parent_id = fork();
	if (parent_id == 0)
	{
		exec_path = get_exec_path(token[0], paths);
		if (exec_path == NULL)
		{
			perror("DOES NOT EXIST");
			exit(0);
		}
		token[0] = exec_path;
		if (execv(exec_path, token) == -1)
		{
			perror("DOES NOT EXIST");
			exit(0);
		}
		free_grid(token);
		free(exec_path);
	}
	else
	{
		wait(&child_status);
	}

	/**free(token);*/
	return (1);
}
