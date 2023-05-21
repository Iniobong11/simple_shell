#include "shell.h"

/**
 * _verfypath - Modifies the path string by adding the current directory.
 * @path: The path string to modify.
 * @pwd:The current directory to add.
 *
 * Return: The modified path string.
 */
char *_verfypath(char *path, char *pwd)
{
	int a = 0, c = 0, i = 0;
	char *newpath = NULL;

	while (path[c] != '\0')
		c++;
	while (path[a] != '\0')
	{
		if (path[0] == ':')
		{
			newpath = _calloc(c + 1, sizeof(char));
			newpath[0] = pwd[0];
			for (i = 0; path[i] != '\0'; i++)
				newpath[i + 1] = path[i];
			free(path);
			path = newpath;
			a++;
			c++;
		}
		else if (path[a] == ':' && path[a + 1] == ':')
		{
			newpath = _calloc(c + 1, sizeof(char));
			for (i = 0; i <= a; i++)
				newpath[i] = path[i];
			newpath[i] = pwd[0];
			for (i = i + 1; path[i] != '\0'; i++)
				newpath[i] = path[i - 1];
			free(path);
			a++;
			path = newpath;
		}
		a++;
	}
	return (path);
}

/**
 * _getpath - Retrieves the PATH environment variable from a string array.
 * @m: The string array to search.
 *
 * Return: The value of the PATH environment variable.
 */
char *_getpath(char **m)
{
	int i, j, k = 0, w = 0, cont = 0;
	char str[] = "PATH=";
	char *path;

	for (i = 0; m[i] != NULL; i++)
	{
		for (j = 0; m[i][j] != '\0'; j++)
		{
			if (cont == 5)
				break;
			if (m[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 5)
			break;
	}
	k = cont;
	if (cont == 5)
	{
		while (m[i][k] != '\0')
		{
			w++;
			k++;
		}
		if (w == 0)
			return (NULL);
		path = _calloc(w + 1, sizeof(char));
		if (path == NULL)
			return (NULL);
		k = 5;
		while (m[i][k] != '\0')
		{
			path[k - 5] = m[i][k];
			k++;
		}
		return (path);
	}
	return (NULL);
}

/**
 * checkbin - Checks if a binary command is available in the directories
 * specified by the PATH environment variable.
 *
 * @b: The binary command to check.
 * @m: The string array containing the directories from the PATH variable.
 *
 * Return: The modified string array 'b'.
 */
char **checkbin(char **b, char **m)
{
	unsigned int i = 0, j = 0, k = 0;
	struct stat veri;
	char *path, *tokens, *buf, *newpath;
	char *valor;

	i = _strlen(b[0]);
	if (b == NULL || i == 0)
		return (NULL);
	path = _getpath(m);
	if (path == NULL)
		return (b);
	newpath = _verfypath(path, ".");
	tokens = _strtoky(newpath, ":");
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		while (tokens[j] != '\0')
			j++;
		buf = _calloc((j + 2), sizeof(char));
		if (buf == NULL)
			perror("No memory");
		for (k = 0; k < j; k++)
			buf[k] = tokens[k];
		buf[k] = '/';
		valor = str_concat(buf, b[0]);
		if (stat(valor, &veri) == 0)
		{
			b[0] = _realloc2(buf, b[0], i, _strlen(valor));
			free(buf), free(valor);
			free(newpath);
			return (b);
		}
		tokens = _strtoky(NULL, ":");
		j = 0;
		free(buf), free(valor);
	}
	free(newpath);
	return (b);
}
