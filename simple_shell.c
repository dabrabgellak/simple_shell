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

/*int main(int argc, char *argv[], char *env[])*/
{
	int i;
	char **paths = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		if (!_starts_with("PATH=", env[i]))
		{
			continue;
		}
		paths = string_split(env[i] + 5, ":");
		break;
	}
	shell_loop(paths);
	return (EXIT_SUCCESS);
}

/**
 * shell_loop - Infinite loop for the shell.
 * @paths: array of paths from environment variable $PATH
 *
 * Return: Nothing.
 */

void shell_loop(char **paths)
{
	char *line = 0;
	char **token;
	int status = 1;

	while (status)
	{
		printf("simple_shell> ");
		line = read_line();
		token = string_split(line, " ");
		status = execute(token, paths);

	}
}
