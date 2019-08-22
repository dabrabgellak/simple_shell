#include "header.h"
/**
 * _strlen - Length of a string.
 * @s: pointer.
 * Return: len.
 */

int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
	{
	}
	return (len);
}

/**
  * _strcmp - compare two strings
  *@s1: pointer
  *@s2: pointer
  *
  * Return: Always 0.
  */
int _strcmp(char *s1, char *s2)
{
	int len;
	for (len = 0; s1[len] != '\0'; len++)
	{
		if (s1[len] < s2[len])
		{
		return (s1[len] - s2[len]);
		}
		if (s1[len] > s2[len])
		{
		return (s1[len] - s2[len]);
		}
	}
		return (0);
}
