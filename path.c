#include "shell.h"

/**
 * check_path - check if command is in the path directories
 * @argv: an array of strings
 *
 * Return: pointer to the linked list
 */
char **check_path(char **argv)
{
	char *pathname, *delim, *path, *path_toks, *pos;
	struct stat st;

	path = envcopy("PATH");
	delim = ":";
	pos = NULL;
	if (path == NULL)
	{
		_puts("PATH variable not found\n");
		_exit(22);
	}
	path_toks = tokenize(path, delim, &pos);
	while (path_toks != NULL)
	{
		pathname = path_concat(path_toks, argv[0]);
		if (stat(pathname, &st) == 0)
		{
			argv[0] = pathname;
			free(path);
			return (argv);
		}
		path_toks = tokenize(NULL, delim, &pos);
		free(pathname);
	}
	free(path);
	return (argv);
}

/**
 * envcopy - Finds path and strdup its value
 * @pathname: PATH name
 *
 * Return: PATH value
 */
char *envcopy(char *pathname)
{
	char **envp, *path;
	int len, i;

	envp = environ;
	len = _strlen(pathname);
	i = 0;
	while (envp[i] != NULL)
	{
		if (_strcmp(envp[i], pathname) == 0)
		{
			path = _strdup(&envp[i][len + 1]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
  * path_concat - concatantate two strs with '/' in betweem
  * @s1: str 1
  * @s2: str 2
  *
  * Return: pointer to new string
  */
char *path_concat(char *s1, char *s2)
{
	char *s, *p;
	int s1len, s2len;

	s1len = s2len = 0;
	s1len = _strlen(s1);
	s2len = _strlen(s2);
	s = malloc((s1len + s2len + 2) * sizeof(char));
	p = s;
	while (*s1 != '\0')
	{
		*s = *s1;
		s++;
		s1++;
	}
	*s = '/';
	s++;
	while (*s2 != '\0')
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (p);
}
