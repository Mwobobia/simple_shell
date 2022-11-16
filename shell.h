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

/*String operations*/
int _atoi(char *s);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *src);

/*Functions Prototypes*/
int _execve(char **argv);
void loop(void);
char **tokenize(char *line);
void check_path(char **string, const char **env);
char *_strcat(char *dest, char *src);
int _puts(char *str);
int _putchar(char c);
char *user_prompt(void);

#endif
