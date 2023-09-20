#include "shell.h"

/**
 * print_int - print integers
 * @n: numper
 * Return: void
 */
void print_int(int n)
{
	int x = 1;

	while (n / x)
	{
		x *= 10;
	}
	x /= 10;
	while (x)
	{
		_putchar((n / x) % 10 + '0');
		x /= 10;
	}
	_putchar(':');
	_putchar(' ');
}
