#include "shell.h"
/**
 * main - main entry point
 *
 * Return: 0 on sucess
 */
int main(void)
{
/*
}

void loop(void)
{
*/
	char *line;
	char **argv;
/*	int status;*/
	do
	{
		line = user_prompt();
		argv = tokenize(line);
<<<<<<< HEAD
		status = _execve(argv);
=======
		_execve(argv);
>>>>>>> b0cb2069209690fad5b4a89c16c85a973280a69c

		free(line);
		free(argv);

	} while (1);

	return (0);

}
