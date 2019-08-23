#include "header.h"

/**
 * main - Calls the loop function.
 *
 * Return: EXIT_SUCCESS.
 */

int main(int argc, char *argv[], char *env[]) {
    int i;
    char **paths = NULL;
    for (i = 0; env[i] != NULL; i++) {
        if (!_starts_with("PATH=", env[i])) {
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
