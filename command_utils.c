#include "shell.h"
#define BUF_SIZE 2048

/**
 * _iscd - Checks if the command is 'cd'.
 * @p: The command and its arguments as a string array.
 * @loop: The loop counter.
 * @v: The original input string array.
 * @myenv: The environment variables.
 *
 * Return: 0 if the command is 'cd', -1 otherwise.
 */
int _iscd(char **p, int loop, char *v[], char **myenv)
{
	char str[] = "cd";
	int i = 0, cont = 0, valor = -1;

	while (p[0][i] != '\0')
	{
		if (i < 2)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 2)
		cont++;

	if (cont == 3)
	{
		_cd(p, loop, v, myenv);
		valor = 0;
	}
	else if (cont == 2)
	{
		_put_err(p, loop, 3, v);
		valor = 0;
	}
	return (valor);
}

/**
 * _cleancd - Clears the contents of the character array.
 * @c: The character array to clean.
 */
void _cleancd(char *c)
{
	int i;

	for (i = 0; i < BUF_SIZE; i++)
		c[i] = 0;
}

/**
 * _fullcd - Copies the content of 'aux' to 'f' and fills the remaining space
 * with null bytes.
 * @f: The destination character array.
 * @aux: The source character array.
 */
void _fullcd(char *f, char *aux)
{
	int w;

	for (w = 0; aux[w] != '\0'; w++)
		f[w] = aux[w];
	for (; w < BUF_SIZE; w++)
		f[w] = 0;
}

/**
 * _cd - Change directory based on the given command.
 * @a: The command and its arguments as a string array.
 * @loop: The loop counter.
 * @v: The original input string array.
 * @myenv: The environment variables.
 */
void _cd(char **a, int loop, char *v[], char **myenv)
{
	int valor = 0, z = 0;
	static char buf[BUF_SIZE];
	static int w = 1;
	char *home, aux[BUF_SIZE] = {0};

	currentstatus(&z);
	if (w == 1)
	{ home = _gethome(myenv);
		if (!home)
			getcwd(home, BUF_SIZE);
		_updateoldpwd(getcwd(buf, BUF_SIZE), myenv);
		_fullcd(buf, _gethome(myenv));
		w++;
	}
	if (a[1] == NULL)
	{
		_cleancd(buf);
		getcwd(buf, BUF_SIZE);
		_updateoldpwd(buf, myenv);
		valor = chdir((const char *)_gethome(myenv));
		_updatepwd(_gethome(myenv), myenv);
	}
	else if (a[1][0] == '-' && a[1][1] == '\0')
	{
		_cleancd(aux), getcwd(aux, BUF_SIZE);
		_updateoldpwd(aux, myenv);
		write(STDOUT_FILENO, buf, BUF_SIZE);
		write(STDOUT_FILENO, "\n", 1);
		valor = chdir((const char *) buf);
		_updatepwd(buf, myenv), _fullcd(buf, aux);
	}
	else
	{
		_cleancd(buf), getcwd(buf, BUF_SIZE);
		_updateoldpwd(buf, myenv);
		valor = chdir((const char *)a[1]);
		_updatepwd(a[1], myenv);
	}
	if (valor == -1)
		_put_err(a, loop, 1, v);
}
