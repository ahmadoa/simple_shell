#include "main.h"

/**
 * _getline - read the input from a stream, alwyas STDIN
 * @lineptr: buffer where the input is stored
 * @sz: size of input buffer
 * @thread: the input file handler/stream
 * Return: number of chars read, -1 if it fails
 */

ssize_t _getline(char **lineptr, size_t *sz, FILE *thread)
{
	static ssize_t input;
	char c = 'x', *buf;
	int readBool;
	ssize_t res;

	if (input == 0)
		fflush(thread);
	else
		return (-1);

	input = 0;
	buf = malloc(sizeof(char) * 120);
	if (!buf)
		return (-1);
	while (c != '\n')
	{
		readBool = read(STDIN_FILENO, &c, 1);
		if (readBool == -1 || (readBool == 0 && input == 0))
		{
			free(buf);
			return (-1);
		}
		if (readBool == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 120)
			buf = _realloc(buf, input, input + 1);
		buf[input] = c;
		input++;
	}
	buf[input] = '\0';
	reassign_pr(lineptr, sz, buf, input);
	res = input;
	if (readBool != 0)
		input = 0;
	return (res);
}
