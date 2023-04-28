#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, <0 if s1 is lower, >0 if s1 is greater
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, result;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	result = (*(s1 + i) - *(s2 + i));

	return (result);
}

/**
 * _isalpha - checks id a char is alphabetic
 * @c: Character
 * Return: 1 if it is, 0 if otherwise
 */

int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _itoa - converts int to string
 * @num: integer to convert
 * Return: converted string
 */

char *_itoa(int num)
{
	char *buffer;
	int len = num_len(num);
	unsigned int num1;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';

	if (num < 0)
	{
		num1 = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = num;
	}

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buffer);
}

/**
 * array_rev - reverses an array
 * @arr: array
 * @len: the length
 * Return: void
 */

void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * num_len - counts the digit length of a number
 * @num: number to count its lenght
 * Return: decimal number
 */

int num_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}
