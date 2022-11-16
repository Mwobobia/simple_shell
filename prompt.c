#include "shell.h"
/**
  * user_prompt - Provide prompt to user
  *
  * Return: line read from terminal
  */
char *user_prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	int atty_mode;

	while (atty_mode)
	{
		atty_mode = isatty(STDIN_FILENO);
		if (atty_mode == 1)
		{
			_puts("Carol$ ");
			if (getline(&line, &len, stdin) != EOF)
			{

				/* We put our argument processing here*/
				return (line);
			}
			else
			{
				_putchar('\n');
				exit(EXIT_FAILURE);
			}
		}
	}

	return (line);

}
