#include "main.h"

/**
 * _strcpy - copies string from src to dest
 * @dest: pointer of destination string
 * @src: pointer of source string
 * Return: pointer of destination string
 */

char *_strcpy(char *dest, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concantenates two strings
 * @dest: pointer of destination string
 * @src: pointer of add to destination
 * Return: pointer of destination string
 */

char *_strcat(char *dest, char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp = src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * _strchr - searches for first occurrence of a char in a string
 * @s: the string
 * @c: char to look for
 * Return: first occ of char, NULL if not found
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

/**
 * _strncmp - compares n chars of s1 and s2
 * @s1: first string
 * @s2: second string
 * @n: number of chars to read
 * Return: 0 if equal, <0 if s1 is lower, >0 s1 is greater
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strdup - duplicates a given string
 * @s: string
 * Return: returns a pointer to the string
 */

char *_strdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}
