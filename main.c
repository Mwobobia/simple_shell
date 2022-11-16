#include "shell.h"
/**
 * main - main entry point
 *
 * Return: 0 on sucess
 */
int main(void)
{

	char *line;
	char **argv;
/*	int status;*/
	do {
		line = user_prompt();
		argv = tokenize(line);
		_execve(argv);

		free(line);
		free(argv);

	} while (1);

	return (0);

}
