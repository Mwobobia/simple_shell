#include "shell.h"
/**
 * _strpbrk - search string @s for the first occurance of any bytes of @accept
 *
 * @s: string to search
 * @accept: string to search @s for bytes from
 *
 * Return: a pointer to the byte @s that matches one of the bytes in accept,
 * otherwise NULL
 */
char *_strpbrk(char *s, const char *accept)
{
	int i, j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (accept[j] == s[i])
				return (s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/**
 * _strspn - get the length of a prefix substring
 *
 * @s: string to search
 * @accept: substring to compare string with
 *
 * Return: number of bytes in th initial segment of @s which consist of only
 * bytes from @accept
 */
int _strspn(char *s, const char *accept)
{
	int i, j, flag, count;

	i = flag = count = 0;
	while (s[i] && count == i)
	{
		for (j = 0; accept[j] && !flag; j++)
		{
			if (accept[j] == s[i])
			{
				count++;
				flag = 1;
			}
		}
		flag = 0;
		i++;
	}
	return (count);
}

/**
 * wordcount - count the number of words in a string
 *
 * @str: string
 *
 * Return: number of words in @str
 */
int wordcount(char *str)
{
	int wc, state, i;

	i = wc = 0;
	state = 0;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
			case '\0':
			case ' ':
			case '\t':
			case '\n':
				if (state == 1)
				{
					state = 0;
					wc++;
				}
				i++;
				break;
			default:
				state = 1;
				i++;
		}
	}
	return (wc);
}

/**
 * _strncmp - compare two strings
 *
 * @s1: first string to compare with @s2
 * @s2: second string from which to compare @s1
 * @n: Length of string to compare to
 *
 * Return: integer value of characters of @s1 minus character number of @s2
 */
int _strncmp(char *s1, char *s2, int n)
{
	char c1, c2;

	while (n > 0)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
		n--;
	}
	return (c1 - c2);
}
