#include "shell.h"
/**
 * main - main entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 *
 * Return: 0 on sucess
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	loop();
	return (0);
}
/**
 * loop - shell loop
 */
void loop(void)
{

	char *line = NULL;
	char **argv;
	int loop_c = 0;
	size_t len = 0;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);

	while (1)
	{
		{
			child = 0;
			_puts("Carol$ ");
			if (getline(&line, &len, stdin) != EOF)
			{
				if (line[0] != '\n' && line[0] != '#')
				{
					argv = make_argv(line);

					if (builtin_check(argv, line) == -1)
					{
						child = 1;
						launch(argv);
					}
					free(argv);
					loop_c++;
				}
			}
			else
			{
				free(line);
				_putchar('\n');
				_exit(0);
			}
		}
	}
}

/**
 * sighandler - Print out the prompt if ctrl-C is hit
 * @sig_num: Unused variable necessary for sighandler function types
 */
void sighandler(int sig_num)
{
	(void)sig_num;
	if (child == 0)
		_puts("\nCarol$ ");
	signal(SIGINT, sighandler);
}
