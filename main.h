#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>
#include <stdarg.h>

/* string tokenizer */
char **tokenize(char *line);

/* handle command execution */
void execmd(char *final, char **argv);

/* handle builtin commands */
int check_builtin(char **argv, char *line);
int handle_builtin(char **argv, char *line);
void exit_function(char **argv, char *line);

/* string functions */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(const char *s);
char *_strdup(char *s);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
int num_len(int num);
char *_itoa(int num);

/* getline function & helpers */
ssize_t _getline(char **lineptr, size_t *sz, FILE *thread);
void *_realloc(void *pr, unsigned int old_size, unsigned int new_size);
void reassign_pr(char **lineptr, size_t *sz, char *buff, size_t inp);

/* strtok function & helpers */
char *_strtok(char *s, char *delim);
unsigned int sim(char delim, const char *s);

/* builtin strtucture */
struct builtin
{
	char *env;
	char *exit;
};

/* environment variables & functions */
extern char **environ;
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
void env_function(void);

/* handle env var commands */
char *get_path(void);
char *concat_path(char *path, char *commandfr);
char *check_path(char **path, char *commandfr);
void free_buffers(char **buf);

#endif /* _MAIN_H_ */