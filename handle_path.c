#include "main.h"

/**
 * _argscmp - compares arguments
 * @argv: tokenized cmd input
 * @ct_output: output counter
 * Return: ct_output
 */

int _argscmp(char **argv, int ct_output)
{
	int count_path = 0;
	struct stat st;
	char *cp_argv = NULL;

	cp_argv = malloc(sizeof(char *) * _strlen(argv[0]));
	_strcpy(cp_argv, argv[0]);

	if (stat(argv[0], &st) == 0 && cp_argv[0] != '/')
		argv[0] = check_path(argv);
	else if (stat(argv[0], &st) == -1)
		argv[0] = check_path(argv);

	if (_strcmp(cp_argv, argv[0]) != 0)
		count_path = 1;

	if (stat(argv[0], &st) == 0)
		ct_output = execmd(argv, ct_output);
	else
	{
		_err(argv[0]);
		ct_output = 127;
	}

	if (count_path == 1)
		free(argv[0]);
	free(cp_argv);
	return (ct_output);
}

/**
 * check_path - checks if path exists in env paths
 * @argv: tokenized cmd input
 * Return: final command
 */

char *check_path(char **argv)
{
	char *path = get_env();
	char *pathcp = NULL, *f_cmd = argv[0];
	struct stat st;
	size_t size;
	char *tknz_path;

	if (!path)
		return (f_cmd);
	tknz_path = _strtok(path, ":");

	while (tknz_path)
	{
		size = _strlen(tknz_path) + _strlen(f_cmd) + 2;
		pathcp = malloc(sizeof(char) * size);
		_strcpy(pathcp, tknz_path);
		_strcat(pathcp, "/");
		_strcat(pathcp, f_cmd);

		if (stat(pathcp, &st) == 0 && st.st_mode & X_OK)
			return (pathcp);

		tknz_path = _strtok(NULL, ":");
		free(pathcp);
	}
	return (f_cmd);
}
