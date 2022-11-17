#include "shell.h"
/**
 * builtin_check - Checks if command is a builtin
 * @argv: argument vector
 * @input: user input
 *
 * Return: returns function call success, -1 on failure
 */
int builtin_check(char **argv, char *input)
{
	int i;
	builtin_t builtin_list[] = {
		{"exit", hsh_exit},
		{"env", hsh_printenv},
		{NULL, NULL}
	};

	for (i = 0; builtin_list[i].name != NULL; i++)
	{
		if (_strcmp(argv[0], "exit") == 0)
			return (builtin_list[0].func_builtin(argv, input));
		if (_strcmp(argv[0], builtin_list[i].name) == 0)
			return (builtin_list[i].func_builtin(argv));
	}
	return (-1);

}
