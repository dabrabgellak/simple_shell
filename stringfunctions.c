#include "header.h"
#include <stdbool.h>
/**
 * _strlen - Length of a string.
 * @s: pointer.
 * Return: len.
 */

int _strlen(const char *s)
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

/**
 * _starts_with - checks whether a string starts with another string.
 *@pre: string prefix.
 *@str: a string.
 *
 * Return: true if a string starts with a given prefix.
 */
bool _starts_with(const char *pre, const char *str)
{
	size_t i;
	size_t lenpre = strlen(pre),
			lenstr = strlen(str);
	if (lenstr < lenpre)
	{
		return (false);
	}
	for (i = 0; i < lenpre; i++)
	{
		if (pre[i] != str[i])
		{
			return (false);
		}
	}
	return (true);
}

/**
 * _concat - concatenates two strings together
 *@str1: str1
 *@str2: str2
 * Return: concatenated string.
 */
char *_concat(const char *str1, const char *str2)
{
	int i, j;
	char *res = malloc((_strlen(str1) + _strlen(str2) + 1) * sizeof(char));

	for (i = 0, j = 0; i < _strlen(str1); i++)
	{
		res[j++] = str1[i];
	}
	for (i = 0; i < _strlen(str2); i++)
	{
		res[j++] = str2[i];
	}
	res[j] = '\0';
	return (res);
}
