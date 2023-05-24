#include "shell.h"
/**
 * _issetenv - confirm whether the line input is setenv
 * @p: pointer array of user input
 * @myenv: environmental copy of variables
 * @loop: no of loops
 * @e: m number of elements
 * @v: arguments of element
 * Return: 0 if successful or -1 if it fails
 */
int _issetenv(char **p, char ***myenv, int *e, int loop, char *v[])
{
	char str[] = "setenv";
	int x = 0, cont = 0, amos = -1;

	x = 0;
	while (p[0][x] != '\0')
	{
		if (x < 6)
		{
			if (p[0][x] == str[x])
				cont++;
		}
		x++;
	}
	if (x == 6)
		cont++;
	if (cont == 7)
	{
		if (p[1] != NULL && p[2] != NULL)
			_setenv(p, myenv, e, loop, v);
		else
			_put_err(p, loop, 5, v);
		amos = 0;
		currentstatus(&amos);
	}
	else if (cont == 6)
	{
		amos = 0;
		_put_err(p, loop, 3, v);
		currentstatus(&amos);
	}
	return (amos);
}
/**
 * _sentenv - addition or mmodification function for
 * environmental variable
 * array of string pointers called the "environment"
 * @myenv: environmental copy
 * @loop: no of loops
 * @p: user input
 * @e: m no of elements
 * @v: arguments of elements
 */
void _setenv(char **p, char ***myenv, int *e, int loop, char *v[])
{
	int a, lg, b, c = 0, cont = 0, p2len = 0, myenvlen = 0;
	char *entirenv, *withequal;

	lg = _strlen(p[1]);
	withequal = str_concat(p[1], "=");
	entirenv = str_concat(withequal, p[2]);
	for (a = 0; (*myenv)[a] != NULL; a++, cont = 0)
	{
		for (b = 0; p[1][b] != '\0' && b < lg; b++)
		{
			if (p[1][b] == (*myenv)[a][b])
				cont++;
		}
		if (cont == lg)
			break;
	}
	if (cont == lg)
	{
		myenvlen = _strlen((*myenv)[a]), p2len = _strlen(p[2]);
		if (p2len < myenvlen)
		{
			for (c = 0; entirenv[c] != '\0'; c++)
				(*myenv)[a][c] = entirenv[c];
			for (; c < myenvlen; c++)
				(*myenv)[a][c] = 0;
		}
		else
		{
			(*myenv)[a] = _realloc((*myenv)[a], myenvlen, _strlen(entirenv));
			for (c = 0; entirenv[c] != '\0'; c++)
				(*myenv)[a][c] = entirenv[c];
		} free(withequal), free(entirenv), *e = *e;
	}
	else if (cont != lg && p[1] != NULL && p[2] != NULL)
	{
		_setenvcreat(myenv, e, entirenv);
		free(withequal), free(entirenv);
	}
	else
		_put_err(p, loop, 5, v);
}
/**
 * _setenvcreat - modify or add an environmental variable
 * array of string pointers called the "environment"
 * @myenv: environmental copy
 * @e: m no of elements
 * @entirenv: arguments of concatenation
 */
void _setenvcreat(char ***myenv, int *e, char *entirenv)
{
	int a = 0, c = 0;
	char **new = NULL;

	new = _calloc(*e + 2, sizeof(char *));
	for (a = 0; (*myenv)[a] != NULL; a++)
	{
		for (c = 0; (*myenv)[a][c]; c++)
			;
		new[a] = _calloc(c + 1, sizeof(char));
		for (c = 0; (*myenv)[a][c] != '\0'; c++)
			new[a][c] = (*myenv)[a][c];
	}
	new[a] = _calloc(_strlen(entirenv) + 1, sizeof(char));
	for (c = 0; entirenv[c] != '\0'; c++)
		new[a][c] = entirenv[c];
	new[a + 1] = NULL;
	*e = *e + 1;
	free_grid((*myenv), *e);
	(*myenv) = new;
}
