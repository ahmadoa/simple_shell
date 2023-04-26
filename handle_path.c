#include "main.h"

/**
 * get_path - gets the env path
 * Return: NULL if it fails, path if it successeds
 */

char *get_path(void)
{
	int i;
	char **env = environ;
	char *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

/**
 * concat_path - concatenates the command we read and each
 * dir from the path
 * @path: tokenized path variable
 * @commandfr: first argument from read input
 * Return: pointer to the concatenated string
 */

char *concat_path(char *path, char *commandfr)
{
	char *buf;
	size_t i = 0, j = 0;

	if (commandfr == 0)
		commandfr = "";
	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(commandfr) + 2));
	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}
	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}

	while (commandfr[j])
	{
		buf[i + j] = commandfr[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}

/**
 * check_path - checks if the concatenated path
 * is in the environment variables
 * @path: tokenized path variable
 * @commandfr: first argument from the read command
 * Return: NULL if it fails, concatenated path if found
 */

char *check_path(char **path, char *commandfr)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = concat_path(path[i], commandfr);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
