#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
	
int main(void)

{
	char *line = NULL;
	size_t len = 0;

	_putchar("$");
	getline(&line, &len, stdin);
	while (!=EOF)
	{
		_putchar("$");

		getline(&line, &len, stdin);

	}
	free(line);

	return (0);
}

