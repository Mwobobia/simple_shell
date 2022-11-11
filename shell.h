#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void check_path(char **string, const char **env);
char *_strcat(char *dest, char *src);
int _puts(char *str);
int _putchar(char c);
int user_prompt(void);

#endif
