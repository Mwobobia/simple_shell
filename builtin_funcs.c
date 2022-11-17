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

/**
 * hsh_printenv - print the list of environment variables
 * @argv: Arguments passed
 *
 * Return: 0 on success, 1 on failure
 */
int hsh_printenv(char **argv)
{
	char c;
	int i, j;

	if (argv[1] == NULL)
	{
		for (i = 0; environ[i]; i++)
		{
			for (j = 0; environ[i][j]; j++)
			{
				c = environ[i][j];
				_putchar(c);
			}
			_putchar('\n');
		}
		return (0);
	}
	return (1);
}

/**
  * hsh_cd - changes the current directory of the process
  * @argv: Arguments passed
  *
  * Return: cd
  */
int hsh_cd(char **argv)
{
	if (argv[1] == NULL)
		argv[1] = "/home";
	if (chdir(argv[1]) != 0)
		perror("hsh");
	return (1);
}
