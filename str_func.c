#include "shell.h"
/**
 * str_concat - creating array with malloc
 * @s1: 1st array
 * @s2: 2nd array
 * Return: null or a pointer
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	unsigned int x = 0, y = 0, z, d = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (*(s1 + x) != '\0')
	{
		x++;
	}
	while (s2[y])
	{
		y++;
	}
	p = _calloc(x + y + 1, sizeof(char));
	if (!p)
	{
		return (NULL);
	}
	else
	{
		for (z = 0; z < x; z++)
		{
			p[z] = s1[z];
		}
		for (z = x; f <= (x + y); z++, d++)
		{
			p[z] = s2[d];
		}
		return (p);
	}
}
/**
 * _strlen - length of string
 * @s: string
 * Return: 0 Always
 */
int _strlen(char *s)
{
	int long = 0;

	while (s[long] != '\0')
	{
		long++;
	}
	return (long);
}
