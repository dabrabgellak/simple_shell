#include "header.h"
#include <unistd.h>

/**
 * read_line - Reads a line.
 * Return: line.
 */

char *read_line()
{
	size_t sizeline;
	char *line = NULL;

	if (getline(&line, &sizeline, stdin) == EOF)
	{	
		exit(0);
	}

	if (line[strlen(line) - 1] == '\n') {
		line[strlen(line) - 1] = '\0';
	}

	return (line);
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

void env_builtin(char *env[])
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]) * sizeof(char));
		write(STDOUT_FILENO, "\n", sizeof(char));
	}
}

/**
 * execute - Executes.
 * @token: All arguments.
 * @paths: All the paths from $PATH environment variable.
 * Return: .
 */

int execute(char *token[], char **paths, char *env[])
{
	pid_t parent_id;
	pid_t child_status;
	char *exec_path;

	if (_strcmp(token[0], "env") == 0)
	{
		env_builtin(env);
		return 1;
	}
	if (_strcmp(token[0], "exit") == 0)
	{
		exit(0);
	}
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
	}
	else
	{
		wait(&child_status);
	}

	return (1);
}
