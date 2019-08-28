#include "header.h"

/**
 * main - Calls the loop function.
 * @argc: the number of arguments passed to the shell.
 * @argv: arguments passed to the shell.
 * @env: environment variables.
 *
 * Return: EXIT_SUCCESS.
 */

int main(__attribute__((unused)) int argc,
	__attribute__((unused))  char *argv[], char *env[])
{
	int i;
	char **paths = NULL;
	bool interactive;

	for (i = 0; env[i] != NULL; i++)
	{
		if (_starts_with("PATH=", env[i]))
		{
			paths = string_split(env[i] + 5, ":");
			break;
		}
	}

	interactive = isatty(STDIN_FILENO);

	shell_loop(argv, paths, env, interactive);
	return (EXIT_SUCCESS);
}

/**
 * shell_loop - Infinite loop for the shell.
 * @paths: array of paths from environment variable $PATH
 * @argv0: To pass no argument number 0.
 * @env: Environment variable
 * @interactive: Boolean (To check if is true of false)
 * Return: Nothing.
 */

void shell_loop(char *argv[], char **paths, char *env[], bool interactive)
{
	char *line = 0;
	char **token;
	int status = 1;

	while (status)
	{
		if (interactive)
		{
			write(STDOUT_FILENO, "$ ", 2 * sizeof(char));
		}
		line = read_line();
		if (line == NULL)
			continue;
		token = string_split(line, " ");
		status = execute(argv, token, paths, env);
		free(line);
		free(token);
	}
}
