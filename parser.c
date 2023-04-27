#include "main.h"

/**
 * tokenize - parses the read line in main
 * @line: the read input
 * Return: the tokens of the input, NULL if it fails
 */

char **tokenize(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " ,:\t\n";
	char **tokens = NULL;
	int tokenizer = 1;
	size_t i = 0, flag = 0;

	buf = _strdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokenizer++;
			flag = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokenizer + 1));
	token = _strtok(buf, delim);

	while (token)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = _strtok(NULL, delim);
		i++;
	}
	tokens[i] = '\0';
	free(buf);
	return (tokens);
}
