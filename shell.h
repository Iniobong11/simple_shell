#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/* setenv */
void _setenvcreat(char ***myenv, int *e, char *entirenv);
int _issetenv(char **p, char ***myenv, int *e, int loop, char *v[]);
void _sentev(char **p, char ***myenv, int *e, int loop, char *v[]);

/* global variables */
char **create_env(char *envp[]);
void _updatepwd(char *buf, char **myenv);
void _updateoldpwd(char *buf, char **myenv);

/* shell functions*/
int _strlen(char *s);
int rev(char **p, int L, char *li, char **v, char ***m, int *e, char *f);
char *str_concat(char *s1, char *s2);
char *_comments(char *line);
char **parsing(char *line);
void functions(char *line, int loop, char *argv[], char ***m, int *e, char *f);
void _yesargv(char *argv[], char *envp[]);
void _noargv(char *argv[], char *envp[]);
int currentstatus(int *status);
int semicolon(char *line, int loop, char **argv);
char  *_getlineav(int *a, char **m, int e, char **av);
char *_getline(int *a, char **m, int e);

/* unsetenv*/
void _unsetenv(char **p, char **myenv, int *e, int loop, char *v[]);
void _errorenv(char **p);
int _isunsetenv(char **p, char **myenv, int *e, int loop, char *v[]);

/*char _getline_av(char *buffer);*/
char **checkbin(char **b, char **m);
void *_realloc2(char *a, char *p, unsigned int old, unsigned int new_size);
int  _isexit(char **p, int L, char *l, char **v, char **m, char *f);
int _atoi(char *s);
int _isenv(char **p, char **myenv);
void _signal(int s);
char *_strtoky(char *s, char *d);
char *_strtoky2(char *s, char *d);
void _frk(char **p, char *l, int a, int L, char **v, int e, char **m, char *f);
void *_calloc(unsigned int nmemb, unsigned int size);
void _cd(char **a, int loop, char *v[], char **myenv);
void _env(char **myenv);
void free_grid(char **grid, int height);
int _iscd(char **p, int loop, char *v[], char **myenv);
char *_changepwd(void);
char *_gethome(char **m);
char *_getpwd(char **m);
char *_changeoldpwd(void);

#define SIZE 1024

/* errors */
void _put_err(char **p, int loop, int sig, char *v[]);
void _builtinerr(char **p);
void _builtinerr2(char **p);
void _errorexit(char **p);
void _errorcd(char **p);
void print_number(int n);
void _errorgarbage(char **p);
void _errorhelp(char **p);

/* help files*/
ssize_t read_cdhelp(char **m);
void _help(char **p, int loop, char *v[], char **m);
ssize_t read_help(char **m);
ssize_t read_exithelp(char **m);
ssize_t read_helphelp(char **m);
void _help_builtin(char **p, int loop, char *v[], char **m);
int _ishelp(char **p, int loop, char *v[], char **m);

#endif
