#include "shell.h"
/**
  * hsh_exit - Implement exit
  * @argv: argument vector
  * @input: exit status input
  *
  * Return: 1 on success
  */
int hsh_exit(char **argv, char *input)
{
	int estatus;

	if (argv[1] == NULL)
	{
		free(input);
		free(argv);
		_exit(0);
	}
	else
	{
		estatus = _atoi(argv[1]);
		if (estatus == -1)
		{
			_puts("Invalid exit status\n");
			return (1);
		}
		free(input);
		free(argv);
		_exit(estatus);
	}
	return (1);

}
