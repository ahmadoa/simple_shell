#include "main.h"

/**
 * _putchar - writes a char to stdout stream
 * @c: char to print
 * Return: 1 on success, -1 or errno otherwise
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - copies a string
 * @dest: destination str
 * @src: source str to copy n char to dest
 * @n: number of chars to copy
 * Return: destination copied string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - length of string
 * @s: string to calucalte it's length
 * Return: the length
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		continue;
	return (i);
}

/**
 * _puts - prints a string
 * @str: pointer to string
 * Return: void
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * _atoi - converts a string to integer
 * @s: string to convert
 * Return: converted string
 */

int _atoi(char *s)
{
	int i, j, n, k;

	i = n = 0;
	k = 1;

	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			k *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + k * ((s[j]) - '0');
		j++;
	}
	return (n);
}
