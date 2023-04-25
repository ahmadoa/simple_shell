#include "main.h"

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if equal, <0 if str1 is lower, >0 if str1 is greater
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0, result;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
		i++;
	result = (*(str1 + i) - *(str2 + i));
	return (result);
}
/**
 * _strlen - calculates the length of a given string
 * @str: the string
 * Return: length of string
 */
int _strlen(const char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
/**
 * _strncmp - compares n chars of str1 and str2
 * @str1: first string
 * @str2: second string
 * @n: number of chars to read
 * Return: 0 if equal, <0 if str1 is lower, >0 if str1 is greater
 */
int _strncmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
/**
 * _strdup - duplicates a given string
 * @str: string
 * Return: returns a pointer to the string
 */
char *_strdup(char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *str != '\0'; str++, i++)
		ptr[i] = s[0];
	ptr[i++] = '\0';
	return (ptr);
}
/**
 * _strchr - searches for first occurrence of a char in a string
 * @str: the string
 * @ch: char to look for
 * Return: first occurrence of char, NULL if not found
 */
char *_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (!ch)
		return (str);
	return (NULL);
}
