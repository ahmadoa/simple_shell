#include "main.h"

/**
 * tokenizer - tokenizes the read input line
 * @line: read input line
 * Return: array of pointers to the tokens, NULL if it fails
 */

char **tokenizer(char *line)
{
	char **tokens, *token;
	int i, buffsz = BUFSIZE;

	if (line == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsz);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}
	token = _strtok(line, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;
	return (tokens);
}
