#include "main.h"

/**
 * print_dec - prints a number in string format
 * @num: the number
 * Return: void
 */

void print_dec(int num)
{
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num == 0)
		write(1, "0", 1);
	else
	{
		char snum[12];
		int i = 0;

		while (num != 0)
		{
			snum[i] = (num % 10) + '0';
			num /= 10;
			i++;
		}
		snum[i] = '\0';
		for (i = i - 1; i >= 0; i--)
			write(1, &snum[i], 1);
	}
}
