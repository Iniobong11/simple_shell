#include "shell.h"
/**
 * print_number - print all whole integers
 * @n: print parameter
 * Return: 0 Always
 */
void print_number(int n)
{
	unsigned int b, count = 1;
	char a;
	unsigned int var1, num, var2, var3 = 1;

	var2 = m;
	num = var2;
	while (num > 9)
	{
		num = num / 10;
		count++;
		var3 = var3 * 10;
	}
	for (b = 1; b <= count; b++)
	{
		var1 = var2 / var3;
		var2 = var2 % var3;
		var3 = var3 / 10;
		a = '0' + var1;
		write(STDERR_FILENO, &a, 1);
	}
}
