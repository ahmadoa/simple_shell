#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;
#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(ch) (write(STDOUT_FILENO, ch, _strlen(ch)))

/**
 * struct built - struct that helps to handle built in commands
 * Description: strcture
 * @blt_cmd: command name
 * @func: function to execute that matches the command
 */
typedef struct built
{
	char *blt_cmd;
	int (*func)(char **line, int err);
} builtin;

/* read & execute input */
int execute(char **t_argv, char *line, int c, char **argv);
char *_getline();
char **tokenizer(char *line);
char *_strtok(char *s, const char *delim);
unsigned int sim(char c, const char *s);
void prompt(void);
void sigHandler(int num);

/* handle errors */
void custom_err(char **argv, int d, char **frcommand);
void display_err(char *frcommand, int c, char **argv);

/* handle builtin commands */
int check_builtin(char **argv);
int handle_builtin(char **line, int err);
void handle_comments(char *line);

/* function for buitltin commands */
void _exit_sh(char **t_argv, char *line, char **argv, int c);
int _cd(char **t_argv, __attribute__((unused)) int err);
/**
 * display_env - displays the env var
 * @t_argv: tokenized read input
 * @err: err
 * Return: 0
 */
int display_env(__attribute__((unused)) char **t_argv,
		__attribute__((unused)) int err);
int _echo(char **t_argv, int err);
int print_echo(char **t_argv);

/* handle env var commands */
void _setenv(char **new_env);
void free_env(char **env);
char *_getenv(char *env_n);
int get_path(char **line);
char *concat_path(char *tok, char *path);

/* handle commands in file functions */
void file_reader(char *fl, char **argv);
void handle_file(char *line, int i, FILE *fd, char **argv);
void exit_file(char **t_argv, char *line, FILE *fd);

/* memory management related functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_buffers(char **t_argv, char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);

/* data types related functions */
void *fill_an_array(void *a, int el, unsigned int len);
int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _atoi(char *s);
void _puts(char *str);
void print_number(unsigned int n);
void print_number_in(int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
char *_itoa(int num);
void array_rev(char *arr, int len);
int num_len(int num);

#endif
