#include "shell.h"

int _execve(char **argv)
{
	int status;
	pid_t child_pid;
	child_pid = fork();
	if(child_pid == -1)
		perror("hsh");
	if(child_pid == 0)

	{
		if(execve(argv[0], argv, NULL) == -1)
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


