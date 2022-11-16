#include "shell.h"
/**
  * _execve - Executes a function
  * @argv: argument vector from user
  *
  * Return: 1 on success
  */
int _execve(char **argv)
{
	int status = 0;
	pid_t child_pid;

	if (argv[0] == NULL)
		return (1);
	child_pid = fork();

	if (child_pid == -1)
		perror("hsh");
	if (child_pid == 0)

	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("hsh");
		free(argv);
		exit(EXIT_SUCCESS);

	}
	else
	{
		wait(&status);
	}
	return (1);

}

