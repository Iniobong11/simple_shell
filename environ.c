#include "shell.h"
/**
 * _isenv - check if the input line is env
 * @p: pointers of array
 * @myenv: environmental copy of variables
 * Return: -1 if fails or 0 if successfully
 */
int _isenv(char **p, char **myenv)
{
	char str[4] = "env";
	int x = 0, y = 0, cont = 0;

	while (p[0][y] != '\0')
		y++;
	if (y == 3)
	{
		while (x < 3)
		{
			if (p[0][x] == str[x])
				cont++;
			x++;
		}
		if (cont == 3)
		{
			_env(myenv);
			return (0);
		}
	}
	return (-1);
}
/**
 * create_env - creation of environmental variables
 * @envp: environmental variables
 * Return: pointer arrays that stores environ variables
 */
char **create_env(char *envp[])
{
	int x, y = 0, c = 0;
	static char **myenv;

	for (x = 0; envp[x] != NULL; x++)
		;
	myenv = _calloc(x + 1, sizeof(char *));
	if (!myenv)
		return (NULL);
	while (envp[y] != NULL)
	{
		c = 0;
		while (envp[y][c] != '\0')
			c++;
		myenv[y] = _calloc(c + 1, sizeof(char));
		if (myenv[y] == NULL)
		{
			free_grid(myenv, y);
			return (NULL);
		}
		for (x = 0; x < c; x++)
			myenv[y][x] = envp[y][x];
		y++;
	}
	myenv[y] = NULL;
	return (myenv);
}
/**
* _env - print function for environmental variables
* environ sets array of pointers to "environment" string
* @myenv: environmental copy of variables
*/
void _env(char **myenv)
{
	int x;

	for (x = 0; myenv[x] != NULL; x++)
	{
		write(STDOUT_FILENO, myenv[x], _strlen(myenv[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
