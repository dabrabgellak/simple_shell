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
	char *line;
	char *arguments;
	int status = 1;

	do {
		printf("simple_shell> ");
		line = read_line();
		arguments = string_split(line);
		/**status = execute(arguments);*/

		free(line);
		free(arguments);
	} while (status);
}
