#include "main.h"

/**
 * get_path - gets and tokenizes the path env var
 * @line: tokenized read command line
 * Return: 1 if it fails, 0 in success
 */
int get_path(char **line)
{
	char *path, *tokens, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	tokens = _strtok(path, ":");
	while (tokens != NULL)
	{
		cmd_path = concat_path(*line, tokens);
		if (stat(cmd_path, &buf) == 0)
		{
			*line = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		tokens = _strtok(NULL, ":");
	}
	free(path);
	return (1);
}

/**
 * concat_path - builds the final command
 * @tok: command to concat
 * @path: path env var
 * Return: tokenized full path, NULL if it fails
 */

char *concat_path(char *tok, char *path)
{
	char *final;
	size_t len;

	len = _strlen(path) + _strlen(tok) + 2;
	final = malloc(sizeof(char) * len);
	if (final == NULL)
		return (NULL);

	memset(final, 0, len);
	final = _strcat(final, path);
	final = _strcat(final, "/");
	final = _strcat(final, tok);
	return (final);
}
