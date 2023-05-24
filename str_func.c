#include "shell.h"

/**
 * str_concat - creating arrays using malloc
 * @s1: no one array
 * @s2: no two array
 * Return: return null or  pointer
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	unsigned int a = 0, b = 0, f, d = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (*(s1 + a) != '\0')
	{
		a++;
	}
	while (s2[b])
	{
		b++;
	}
	p = _calloc(a + b + 1, sizeof(char));
	if (!p)
	{
		return (NULL);
	}
	else
	{
		for (f = 0; f < a; f++)
		{
			p[f] = s1[f];
		}
		for (f = a; f <= (a + b); f++, d++)
		{
			p[f] = s2[d];
		}
		return (p);
	}
}

/**
 * _strlen - returns string lengt
 * @s: string of values
 * Return: 0 Always
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
