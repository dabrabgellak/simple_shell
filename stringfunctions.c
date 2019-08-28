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
	int len = 0;

	/** Traverse s1 */
	while (s1[len] != '\0' && s2[len] != '\0')
	{
		/** If s1 not equals to s2 */
		if (s1[len] != s2[len])
		{
			/** Returns the difference between both */
			return (s1[len] - s2[len]);
		}
		len++;
	}
	/** s1 and s2 of the same size - return 0 */
	if (s1[len] == '\0' && s2[len] == '\0')
		return (0);
	/** s2 is longer than s1 - return -1 */
	if (s1[len == '\0'])
		return (-1);
	/** s1 is longer than s2 - return 1 */
	return (1);
}

/**
 * _starts_with - Boolean function that checks two strings
 *@pre: string 1
 *@str: string 2
 *Return: true or false depends of the case.
 */
bool _starts_with(const char *pre, const char *str)
{
	size_t i;
	size_t lenpre = _strlen(pre),
			lenstr = _strlen(str);
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
	int count, secount;
	char *res = malloc((_strlen(str1) + _strlen(str2) + 1) * sizeof(char));

	for (count = 0, secount = 0; count < _strlen(str1); count++)
	{
		res[secount++] = str1[count];
	}
	for (count = 0; count < _strlen(str2); count++)
	{
		res[secount++] = str2[count];
	}
	res[secount] = '\0';
	return (res);
}
