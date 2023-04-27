#include "main.h"

/**
 * get_env - gets the environment path
 * Return: the env path
 */

char *get_env(void)
{
	int i;
	char **env = NULL, *path = NULL;

	env = environ;

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp("PATH", env[i], 4) == 0)
			path = env[i];
	}

	if (path != NULL)
	{
		while (*path != '=')
			path++;
		path++;
	}
	return (path);
}
