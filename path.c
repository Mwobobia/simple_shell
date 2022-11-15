#include "shell.h"

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


/**
 * check_path - check if command is in the path directories
 * @string: an array of strings
 * @env: an array of env vars
 * Return: pointer to the linked list
 */
void check_path(char **string, const char **env)
{
	char *str1, *str2, *path;
	int i, start, last;

	str1 = _strcat("/", string[0]);
	path = getenv(*env);
	if (path == NULL)
	{
		free(str1);
		exit(0);
	}
	start = i = last = 0;
	while (path[i])
	{
		if (path[i] == ':' || path[i + 1] == '\0')
		{
			if (path[i + 1] == '\0')
			{
				i += 1;
				last = 1;
			}
			else
				path[i] = '\0';
			str2 = _strcat(path + start, str1);
			if (access(str2, F_OK) == 0)
			{
free(string[0]);
				string[0] = str2;
				free(str1);
				return;
			}
			free(str2);
			if (last)
				break;
			path[i] = ':';
			start = i + 1;
		}
		i += 1;
	}
	free(str1);
}
