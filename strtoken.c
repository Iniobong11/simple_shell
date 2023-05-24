#include "shell.h"
/**
 * _sch - check char inside a string
 * @s: review the string
 * @c: find char
 * Return: 0 if unsuccessful or 1
 */
int _sch(char *s, char c)
{
	int con = 0;

	while (s[con] != '\0')
	{
		if (s[con] == c)
	{
		break;
	}
		con++;
	}
	if (s[con] == c)
		return (1);
	else
		return (0);
}
/**
 * _strtoky - string taken to be tokenized and input delimiter
 * @s: delimiters string
 * Return: 1st partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimate;
	int x = 0, y = 0;

	if (!s)
		s = ultimate;
	while (s[x] != '\0')
	{
		if (_sch(d, s[x]) == 0 && s[x + 1] == '\0')
		{
			ultimate = s + x + 1;
			*ultimate = '\0';
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 0)
			x++;
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 1)
		{
			ultimate = s + x + 1;
			*ultimate = '\0';
			ultimate++;
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 1)
		{
			y++;
			x++;
		}
	}
	return (NULL);
}
/**
 * _strtoky2 - token function
 * @s: cutting strings into parts
 * @d: delimiters
 * Return: 1st partition
 */
char *_strtoky2(char *s, char *d)
{
	static char *ultimate;
	int x = 0, y = 0;

	if (!s)
		s = ultimate;
	while (s[x] != '\0')
	{
		if (_sch(d, s[x]) == 0 && s[x + 1] == '\0')
			x++;
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 0)
			x++;
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 1)
		{
			ultimate = s + x + 1;
			*ultimate = '\0';
			ultimate++;
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 1)
		{
			y++;
			x++;
		}
	}
	return (NULL);
}
