#include "header.h"

/**
 * env_builtin - Function that prints environment variables
 * @env: Environment variable
 * Return: Nothing.
 */

/**void env_builtin(char *env[])
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]) * sizeof(char));
		write(STDOUT_FILENO, "\n", sizeof(char));
	}
}*/

/**
 *
 *
 *
 *
 */

/** Declaration of functions */
void help_builtin(char *line);
void exit_builtin(char *line);
void cd_buildin(char *line);
void env_builtin(char *env[]);

/** Struct for the commands */
char *builtin_command[]
{
	"help",
	"exit",
	"cd",
	"env"
};

/** Accesing to the address of each function with a struct */
void *builtin_command
{
	&help_builtin,
	&exit_builtin,
	&cd_builtin
	&env_builtin
};

/** Making help come to life*/
/** Making exit come to life*/
/** Making cd come to life*/
/** Making env come to life */

/**
 * env_builtin - Function that prints environment variables
 * @env: Environment variable
 * Return: Nothing.
 */

void env_builtin(char *env[])
{
        int i;

        for (i = 0; env[i] != NULL; i++)
        {
                write(STDOUT_FILENO, env[i], _strlen(env[i]) * sizeof(char));
                write(STDOUT_FILENO, "\n", sizeof(char));
        }
}
