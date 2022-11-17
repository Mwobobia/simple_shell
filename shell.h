#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
/* Global variable */
extern char **environ;
int child;

/**
 *builtin_s - structure to implement built-in functions
 *
 */
typedef struct builtin_s
{
	char *name;
	int (*func_builtin)();
} builtin_t;

/*Built in functions prototypes*/
int builtin_check(char **argv, char *input);
int hsh_exit(char **argv, char *input);
int hsh_printenv(char **argv);
int hsh_cd(char **argv);

/*String operations*/
int _atoi(char *s);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *src);
char *_strpbrk(char *s, const char *accept);
int _strspn(char *s, const char *accept);
int wordcount(char *str);


/*Functions Prototypes*/
void launch(char **argv);
void _execve(char **argv);
void loop(void);
char *tokenize(char *line, const char *delim, char **saveptr);
char *_strcat(char *dest, char *src);
int _puts(char *str);
int _putchar(char c);
char *user_prompt(void);
char **make_argv(char *input);
void sighandler(int sig_num);

/*Path operations*/
char *envcopy(char *pathname);
char **check_path(char **argv);
char *path_concat(char *s1, char *s2);


#endif
