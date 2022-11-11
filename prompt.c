#include "shell.h"

int user_prompt(void)

{
	char *line = NULL;
	size_t len = 0;
	int atty_mode;

	while(atty_mode)
	{
		atty_mode = isatty(STDIN_FILENO);
		if(atty_mode == 1)
		{
			_puts("Carol$ ");
			if(getline(&line, &len, stdin) != EOF)
			{

				/* We put our argument processing here*/
				printf("Received: %s", line);
			}
			else
			{
				_putchar('\n');
				exit(EXIT_FAILURE);
			}
		}
	}

	/**
	 * Previous Code

	 while (getline(&line, &len, stdin)!=EOF)
	 {
	 _puts("Carol$ ");

	 }
	 *
	 */
	free(line);

	return (0);
}
