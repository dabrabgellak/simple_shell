#include "header.h"

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
