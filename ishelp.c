#include "shell.h"
/**
 * _ishelp - builtin if argument [0] is help
 * @p: pointer's input
 * @loop: counter connections
 * @v: input arguments
 * @m: environmental copy of variables
 * Return: 0 if help is successful, or -1 if not.
 */
int _ishelp(char **p, int loop, char *v[], char **m)
{
	char str[] = "help";
	int n = 0, cont = 0, amos = -1;

	while (p[0][n])
	{
		if (n < 4)
		{
			if (p[0][n] == str[n])
				cont++;
		}
		n++;
	}
	if (i == 4)
		cont++;

	if (cont == 5)
	{
		_help(p, loop, v, m);
		amos = 0;
	}
	return (amos);
}
/**
 * _help_builtin - builtin of help
 * @p: pointer;s input
 * @loop: counter connections
 * @v: input arguments
 * @m: environmental copy of variables
 * environmental copy of variables
 * Return: 0
 */
void _help_builtin(char **p, int loop, char *v[], char **m)
{
	char str1[3] = "cd", str2[5] = "exit", str3[5] = "help";
	int k = 0, l = 0, cont = 0, cont2 = 0, n = 1;

	while (p[n] != NULL)
	{
		l = 0;
		cont = 0, cont2 = 0;
		while (p[n][l] != '\0')
			l++;
		if (l == 2)
		{
			for (k = 0; k < 2; k++)
				if (p[n][k] == str1[k])
					cont++;
			if (cont == 2)
				read_cdhelp(m);
			else
				_put_err(p, loop, 1, v);
		}
		else if (l == 4)
		{
			for (k = 0 ; k < 4; k++)
				if (p[n][k] == str2[k])
					cont++;
			if (cont == 4)
				read_exithelp(m);
			for (k = 0 ; k < 4; k++)
				if (p[n][k] == str3[k])
					cont2++;
			if (cont2 == 4)
				read_helphelp(m);
			else if (cont != 4 && cont2 != 4)
				_put_err(p, loop, 1, v);
		}
		else
			_put_err(p, loop, 1, v);
		n++;
	}
}
/**
 * _help - help the written error
 * @p: pointer;s input
 * @loop: counter connections
 * @v: input arguments
 * @m: environmental copy of variables
 * environmental copy of variables
 * Return: 0
 */
void _help(char **p, int loop, char *v[], char **m)
{
	if (p[0] != NULL && p[1] == NULL)
	{
		read_help(m);
	}
	else
	{
		_help_builtin(p, loop, v, m);
	}
}
