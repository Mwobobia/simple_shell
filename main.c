#include "shell.h"
/**
 * main - main entry point
 *
 * Return: 0 on sucess
 */
int main(void)
{
<<<<<<< HEAD

=======
	
>>>>>>> e14e36a001c9b7bace1b0edaa50bb92703e10b26
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
