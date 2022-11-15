#include "shell.h"
/**
  * main - main entry point
  *
  * Return: 0 on sucess
  */
int main(void)
{
	char *line;
	__attribute__((unused))char **argv;

	line = user_prompt();
	argv = tokenize(line);
	
	return (0);
}

