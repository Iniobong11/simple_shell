#include "shell.h"

/**
 * _gethome - function for HOME env
 * @m: environmenal copy of variables
 * Return: string found in a HOME env variable
 */
char *_gethome(char **m)
{
	int k, l, n, cont = 0;
	char str[] = "HOME=";
	char *home = NULL;

	for (k = 0; m[k] != NULL; k++)
	{
		for (l = 0; m[k][l] != '\0'; l++)
		{
			if (cont == 5)
				break;
			if (m[k][l] == str[l])
				cont++;
			else
				break;
		}
		if (cont == 5)
			break;
	}
	if (cont == 5)
	{
		home = m[k];
		for (n = 0; n < 5; n++)
		{
			home++;
		}
	}
	return (home);
}
