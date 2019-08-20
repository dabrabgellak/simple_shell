#include "header.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
void shell_loop(void)
{
	char *line;
	/*char **arguments;*/
	int status;

	do
	{
		printf("$ ");
		line= read_line();

		free(line);
	}
	while(status);
}


