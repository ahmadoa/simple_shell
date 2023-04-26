#include "main.h"

/**
 * _strtok - seperates a string into tokens
 * using a delimiter/seperator
 * @s: the string to tokenize
 * @delim: delimiter
 * Return: NULL if it fails, the tokens if it successeds
 */

char *_strtok(char *s, char *delim)
{
	long int i;
	static char *first_tok;
	static char *second_tok;

	if (s == NULL && delim == NULL)
		return (NULL);
	if (s != NULL)
		second_tok = s;
	first_tok = second_tok;
	if (first_tok == NULL)
		return (NULL);
	for (i = 0; second_tok[i] != 0; i++)
	{
		if (sim(second_tok[i], delim) == 1)
			break;
	}
	if (second_tok[i] == 0 || second_tok[i] == 35)
	{
		return (NULL);
	}
	first_tok = second_tok + i;
	second_tok = first_tok;
	for (i = 0; second_tok[i] != 0; i++)
	{
		if (sim(second_tok[i], delim) == 0)
			break;
	}
	if (second_tok[i] == 0)
		second_tok = NULL;
	else
	{
		second_tok[i] = 0;
		second_tok += i + 1;
	}
	return (first_tok);
}
