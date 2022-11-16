#include "shell.h"

char **tokenize(char *line)
{
	const char *delim = " \t\r\n\a";
	char *token;
	char **toks;
	int i = 0;


	toks = malloc(sizeof(char*) * 64);
	if (toks == NULL)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);

	while(token != NULL)
	{
		toks[i] = strdup(token);
		i++;
		token = strtok(NULL,delim);
	}
	toks[i] = NULL;
	return toks;
}

