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
	int i, len;
	builtin_t builtin_list[] = {
		{"exit", hsh_exit},
		{NULL, NULL}
	};

	len = strlen(argv[0]);
	for (i = 0; builtin_list[i].name != NULL; i++)
	{
		if (strncmp(argv[0], "exit", 4) == 0)
			return (builtin_list[0].func_builtin(argv, input));
		if (strncmp(argv[0], builtin_list[i].name, len) == 0)
			return (builtin_list[i].func_builtin(argv));
	}
	return (-1);

}
