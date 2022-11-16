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
	
/*
	pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execve(argv[0], argv, NULL) == -1) {
      perror("hsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("hsh");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
  */
}


