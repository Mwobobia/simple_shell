#include "shell.h"
/**
 * main - main entry point
 *
 * Return: 0 on sucess
 */
int main(void)
{



	/*}

	  void loop(void)
	  {
	 */
	char *line;
	char **argv;
	__attribute__((unused))int status;
	do
	{
		line = user_prompt();
		argv = tokenize(line);
//		status = _execve(argv);

		free(line);
		free(argv);

	} while (1);
	
	return(0);
}
