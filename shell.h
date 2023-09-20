#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<signal.h>
void erp(int now, char *command);
void pt(int now);
char *to_st(int now);
void ptt(int now);
int chec(char *input, int now);
void dish(char **command, char ***args, int *i, int j, char **argv, int now);
void fro(char **command, char **input, char ***args, int k);
void fors(int *i, int *co, char *input);
char *our_get_line(void);
void comma(char **input, int *now, char **argv);
void fre(char **args);
void null_all(char **input, char **command, char ***args);
int handle_echo(char *input, char *command, char ***args);
int rep(char *input);
void fre_argv(char **argv);
void fill(char ***argv);
void fre1(char **args);
int len_args(char ***args);
void assign_env(char **var, char *s1, char *s2);
void handle_env(char **command, char ***args, int n, char **argv);
void change_dir(char **path, int now, char **argv);
int isfound(char *name);
int findd(char *st1, char *st2, char **argv);
char *getpath(char **name, int len, char **argv, int now);
extern char **environ;
void update(char **argv, char *value);
char *var(char *st, char **argv);
void oldpwd(char **argv, char *value);
void value(char **args, char **argv);
int call_env(int n, char **argv);
void unset_env(char *var, char **argv);
int con(char **command, char ***args, int now, char **argv);
void split(char *input, char **command, char ***args);
int _putchar(char c);
int convert(char ***args, int *res);
void execute(char *command, char **args, char **argv, int now);
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int cmp(char *input1, char *input2);
void print_int(int n);
#endif
