#include "main.h"

/**
 * print_number - prints an unsigned int
 * @n: the integer
 * Return: void
 */

void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);
	_putchar(x % 10 + '0');
}

/**
 * print_number_in - prints an integer
 * @n: the integer
 * Return: void
 */

void print_number_in(int n)
{
	unsigned int t = n;

	if (n < 0)
	{
		_putchar('-');
		t = -t;
	}
	if ((t / 10) > 0)
		print_number(t / 10);
	_putchar(t % 10 + '0');
}
