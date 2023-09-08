#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;
int _putchar(char c);
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);


#endif
