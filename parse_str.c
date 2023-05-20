#include "shell.h"

/**
 * Counter - Counts the occurrences of characters from 'lim' in 'L'.
 * @L: The string to search in.
 * @lim: The characters to count.
 *
 * Return: The number of occurrences.
 */
int Counter(char *L, char *lim)
{
	int ct = 0, num = 0, ct2 = 0;

	while (lim[ct2] != '\0')
	{
		ct = 0;
		while (L && L[ct] != '\0')
		{
			if (L[ct] != lim[ct2])
			{
				if (L[ct + 1] == lim[ct2] || L[ct + 1] == '\0')
					num++;
			}
			ct++;
		}
		ct2++;
	}
	return (num);
}

/**
 * parsing - Parses the input line into tokens.
 * @line: The input line to parse.
 *
 * Return: A double pointer to the tokens.
 */
char **parsing(char *line)
{
	char *token = NULL, **p = NULL;
	int length = 0, j = 0, i = 0, buffsize = 0;

	if (line == NULL)
		return (NULL);
	buffsize = Counter(line, " \t");
	p = _calloc((buffsize + 1), sizeof(char *));
	if (!p)
	{
		perror("No memory");
		return (NULL);
	}
	token = _strtoky(line, " \t\n");
	if (!token)
	{
		free(p);
		return (NULL);
	}
	while (token)
	{
		while (token[length] != '\0')
			length++;
		p[j] = _calloc((length + 1), sizeof(char));
		if (p[j] == NULL)
		{
			free_grid(p, j);
			perror("No memory");
			return (NULL);
		}
		for (i = 0; i < length; i++)
			p[j][i] = token[i];

		length = 0;
		j++;
		token = _strtoky(NULL, " \t\n");
	}
	p[j] = NULL;
	return (p);
}
