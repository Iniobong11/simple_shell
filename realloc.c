#include "shell.h"
/**
 * _realloc - copy the content and change the size
 * @ptr: reallocate malloc pointer
 * @old_size: no of old btyes
 * @new_size: no of new btyes
 * Return: 0 Always
 */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int n;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = _calloc(new_size + 1, sizeof(char));
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = _calloc(new_size + 1, sizeof(char));
		if (!p)
			return (NULL);
		for (n = 0; n < old_size; n++)
			p[n] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = _calloc(new_size + 1, sizeof(char));
		if (!p)
			return (NULL);
		for (n = 0; n < new_size; n++)
			p[n] = *((char *)ptr + n);
		free(ptr);
	}
	return (p);
}
/**
 * _realloc2 - copy the content and change the size
 * @a: addition of strings
 * @p: reallocate malloc pointer
 * @old: no of old btyes
 * @new_size: no of new btyes
 * Return: 0 Always
 */
void *_realloc2(char *a, char *p, unsigned int old, unsigned int new_size)
{
	char *pa = NULL;
	unsigned int x, y = 0;

	if (new_size == old)
		return (p);
	if (p == NULL || a == NULL)
	{
		pa = _calloc(new_size + 1, sizeof(char));
		if (!pa)
			return (NULL);
		return (pa);
	}
	while (a[y] != '\0')
		y++;
	if (new_size == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	if (new_size > old)
	{
		pa = _calloc(new_size + 1, sizeof(char));
		if (!pa)
			return (NULL);
		for (x = 0; x < y; x++)
			pa[x] = a[x];
		for (; x <= new_size; x++)
			pa[x] = *((char *)p + (x - y));
		free(p);
	}
	else
	{
		pa = _calloc(new_size, sizeof(char));
		if (!pa)
			return (NULL);
		for (x = 0; x < new_size; x++)
			pa[x] = *((char *)p + x);
		free(p);
	}
	return (pa);
}
