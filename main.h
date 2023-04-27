#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>

#define DELIM " ,:\n\t"
#define STDOUT STDOUT_FILENO
#define STDIN STDIN_FILENO
#define STDERR STDERR_FILENO

/* string tokenizer */
char **tokenize(char *line);

/* read input */
char *c_reader(void);

/* handle command execution */
int execmd(char **argv, int ct_output);
void _err(char *line);

/* handle builtin commands */
int check_builtin(char **argv, int ct_output, char *line);
int handle_builtin(char **argv, int ct_output, char *line);

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

/* environment variables & functions */
extern char **environ;
char *get_env(void);
int _argscmp(char **argv, int ct_output);
char *check_path(char **argv);

#endif /* _MAIN_H_ */
