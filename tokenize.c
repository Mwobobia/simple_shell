#include "shell.h"
/**
 * make_argv - make array of pointer arguments
 *
 * @input: User input to be turned into arguments
 *
 * Return: argument list
 */
char **make_argv(char *input)
{
	char **argv, *arg, *pos, *delims;
	int i, wc;

	pos = NULL;
	delims = "\n\t \r\a";
	i = 0;
	wc = wordcount(input);
	argv = malloc(sizeof(char *) * (wc + 1));
	arg = tokenize(input, delims, &pos);
	while (arg != NULL)
	{
		argv[i] = arg;
		if (argv[i][0] == '#')
			break;
		arg = tokenize(NULL, delims, &pos);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * tokenize - create tokens using delimiters
 * @line: argument from readline
 * @delim: delimiter
 * @saveptr: saves pointer
 *
 * Return: toks, argument vector
 */
char *tokenize(char *line, const char *delim, char **saveptr)
{
	char *token;
	int i = 0;

	if (line == NULL)
		line = *saveptr;
	line += _strspn(line, delim);
	if (*line == '\0')
	{
		*saveptr = line;
		return (NULL);
	}
	token = line;
	line = _strpbrk(line, delim);
	if (line == NULL)
	{
		while (token[i] != '\0')
			i++;
		*saveptr = token + i;
	}
	else
	{
		*line = '\0';
		*saveptr = line + 1;
	}
	return (token);
}
