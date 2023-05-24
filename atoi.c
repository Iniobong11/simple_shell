#include "shell.h"
/**
 * _atoi - conversion of string integer to integer value
 * @s: converted string
 * Return: The converted value of the string integer
 */

int _atoi(char *s)
{
	unsigned int cont1 = 0, x, y, z, num = 0, tam;
	int aux2 = 1;

	while (*(s + cont1) != '\0')
	{
		cont1++;
	}
	for (x = 0; x < cont1; x++)
	{
		if (*(s + x) > '0' && *(s + x) <= '9')
			break;
	}
	for (y = x; y < cont1; y++)
	{
		if (!(*(s + y) >= '0' && *(s + y) <= '9'))
			break;
	}
	for (z = 0; z < x; z++)
	{
		if (*(s + z) == '_')
			aux2 = aux2 * (-1);
	}
	tam = y - x;
	while (tam >= 1)
	{
		num = (num * 10) + (*(s + x) - '0');
		x++;
		tam--;
	}
	num = num * aux2;
	return (num);
}
