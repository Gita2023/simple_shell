#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/*const_value*/
#define OUT_QUERY 1
#define INSIDE_QUERY 2
#define WAY_QUERY 3
#define NOTCORRECT_QUERY -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct describe - constract of shell code 
 *
 *@query_name: name of the query
 *@func: run the query
 */

typedef struct describe
{
	char *query_name;
	void (*func)(char **query);
} describe_func;

extern char **environ;
extern char *way;
extern char **condition;
extern char *value_shell;
extern int status;

/*output_format*/
void output(char *, int);
char **runer(char *, char *);
void delete_newline(char *);
int _lengthstr(char *);
void _copystring(char *, char *);

/*display_format*/
int _stringcmp(char *, char *);
char *_stringcon(char *, char *);
int _stringpre(char *, char *);
int _stringcom(char *, char *);
char *_stringloc(char *, char);
char *_string_tokr(char *, char *, char **);
int _stringint(char *);
void *_factloc(void *ptr, unsigned int old_size, unsigned int new_size);
void control_c(int);
void delete_comment(char *);

/*load_shelll*/
int pass_query(char *);
void run_query(char **, int);
char *fix_way(char *);
void (*retrive_fun(char *))(char **);
char *_rollbackfun(char *);

/*condition_function*/
void ENVIROMENT(char **);
void OUTSIDE(char **);

/*startup_os*/
extern void userexper_useless(void);
extern void starter_fun(char **live_query, int query_type);

#endif /*SHELL_H*/
