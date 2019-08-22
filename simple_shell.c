#include "header.h"

/**
 * main - Calls the loop function.
 *
 * Return: EXIT_SUCCESS.
 */

int main(void)
{
	shell_loop();
	return (EXIT_SUCCESS);
}

/**
 * shell_loop - Infinite loop for the shell.
 * Return: Nothing.
 */

void shell_loop(void)
{
	char *line = 0;
	char **token;
	int status = 1;

	while (status)
	 {
		printf("simple_shell> ");
		line = read_line();
		token = string_split(line);
		status = execute(token);

	}
}
