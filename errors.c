#include "main.h"

/**
 * custom_err - handles custom errors
 * @argv: shell program name
 * @c: number of error
 * @frcommand: first command from read line
 * Return: void
 */

void custom_err(char **argv, int c, char **frcommand)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(frcommand[0]);
	PRINTER(": Illegal number: ");
	PRINTER(frcommand[0]);
	PRINTER("\n");
	free(er);
}

/**
 * display_err - display error
 * @frcommand: first command from read line
 * @c: loop error counter
 * @argv: void
 */

void display_err(char *frcommand, int c, char **argv)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(frcommand);
	PRINTER(": not found\n");
	free(er);
}
