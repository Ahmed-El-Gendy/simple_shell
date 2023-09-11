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
#include <fcntl.h>
int handle_echo(char *input, char **command, char ***args);
int rep(char **input);
void change_dir(char **path);
int isfound(char *name);
char *getpath(char *name, int len);
extern char **environ;
int con(char **command, char **args);
void split(char *input, char **command, char ***args);
int _putchar(char c);
int convert(char ***args, int *res);
void execute(char *command, char **args);
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int cmp(char *input1, char *input2);
#endif
