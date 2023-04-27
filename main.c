#include "main.h"

/**
 * sigHandler - handle ctrl+c
 * @num: signal val
 * Return: void
 */
void sigHandler(int num)
{
	(void)num;
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}

/**
 * main - shell entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: entry value
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *line, **av_tok;
	int i = 0, entry = 1, st = 0;

	if (argv[1] != NULL)
		file_reader(argv[1], argv);
	if (signal(SIGINT, sigHandler) == SIG_ERR)
	{
		perror("couldn't catch signal");
		exit(EXIT_FAILURE);
	}
	while (entry)
	{
		i++;
		if (isatty(STDIN_FILENO))
			prompt();
		else
			write(STDERR_FILENO, "\n", 1);
		line = _getline();
		if (line[0] == '\0')
			continue;
		av_tok = tokenizer(line);
		if (_strcmp(av_tok[0], "exit") == 0)
		{
			_exit_sh(av_tok, line, argv, i);
		}
		else if (check_builtin(av_tok) == 0)
		{
			st = handle_builtin(av_tok, st);
			free_buffers(av_tok, line);
			continue;
		}
		else
			st = execute(av_tok, line, i, argv);
		free_buffers(av_tok, line);
	}
	return (entry);
}
