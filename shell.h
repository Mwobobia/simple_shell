#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int _puts(char *str);
int _putchar(char c);
int user_prompt(void);

#endif
