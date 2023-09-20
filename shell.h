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
void erp(int now, char *command);
void pt(int now);
void ptt(int now);
int chec(char *input, int now);
void dish(char **command, char ***args, int *i, int j, int now);
void fro(char **command, char **input,char ***args, int k);
void fors(int *i, int *co, char *input);
char *our_get_line(void);
int comma(char **input, int now);
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
void change_dir(char **path,int now);
int isfound(char *name);
char *tost(int now);
int findd(char *st1, char *st2, char **argv);
char *getpath(char **name, int len);
extern char **environ;
void update(char **argv, char *value);
char *var(char *st);
void oldpwd(char **argv, char *value);
void value(char **args);
int call_env(int n);
void unset_env(char *var, char **argv);
int con(char **command, char ***args, int now);
void split(char *input, char **command, char ***args);
int _putchar(char c);
int convert(char ***args, int *res);
void execute(char *command, char **args, int now);
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int cmp(char *input1, char *input2);
void print_int(int n);
#endif
