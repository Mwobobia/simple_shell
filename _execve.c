#include "shell.h"

/**
  * launch - launches the execve command by checking path first
  * @argv: argument vector
  *
  * Returns: void
  */
void launch(char **argv)
{
	if (argv[0][0] == '/')
		_execve(argv);
	else
	{
		argv = check_path(argv);
		if (argv != NULL)
			_execve(argv);
	}
}

/**
  * _execve - Executes a function
  * @argv: argument vector from user
  *
  * Return: void
  */
void _execve(char **argv)
{
	int status = 0;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("hsh");
		_exit(99);
	}
	if (child_pid == 0)

	{
		if (execve(argv[0], argv, environ) == -1)
			perror("hsh");
		free(argv);
		_exit(1);

	}
	else
	{
		wait(&status);
	}
}

