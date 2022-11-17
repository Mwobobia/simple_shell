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
