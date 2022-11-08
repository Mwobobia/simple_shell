#include "shell.h"
	
int user_prompt(void)

{
	char *line = NULL;
	size_t len = 0;

	while (getline(&line, &len, stdin)!=EOF)
	{
		_putchar('$');
		_putchar(' ');


	}
	free(line);

	return (0);
}

