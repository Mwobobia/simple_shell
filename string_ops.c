#include "shell.h"

/**
 * _atoi - print integers
 * @s: integer to print
 * Return: (e) the integer
 */
int _atoi(char *s)
{
	int i, num;

	i = num = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		num = num * 10;
		num += s[i] - '0';
		i++;
	}
	return (num);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length of a string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: outputs the difference of s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (*(s1 + i) - *(s2 + i));
}

/**
 * _strdup - string duplicator
 * @src: source
 *
 * Return: returns duplicated strings
 */

char *_strdup(char *src)

{
	char *new;
	int i;
	int size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/**
 * _strcat - contatenate two strings
 *
 * @dest: Destination string
 * @src: Source string
 *
 * Return: 0
 */


char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] += src[j];
		i++;
		j++;
	}

	dest += '\0';
	return (dest);
}


