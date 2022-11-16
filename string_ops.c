#include "shell.h"

/**
 * _atoi - print integers
 * @s: integer to print
 * Return: (e) the integer
 */
int _atoi(char *s)
{
	int a, b, si, j;

	unsigned int e;

	a = 0;
	si = 1;
	e = 0;

	j = 0;

	while (s[a] != '\0')
	{
		b = s[a];
		if (b == 45)
		{
			si = si * (-1);
		}
		if (b >= 48 && b <= 57)
		{
			b = s[a] - 48;
			if (e == 0)
			{
				e = b;
			}
			else
			{
				e = (e * 10) + b;
				++j;
			}
		}
		else if (j > 0)
		{
			break;
		}
		++a;
	}
	e = e * si;

	return (e);

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
	new = malloc(sizeof(char) * (size + 1))
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
