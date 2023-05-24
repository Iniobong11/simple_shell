#include "shell.h"

/**
 * free_grid - free one matrix
 * @grid: interconection of  matrices
 * @height: height (top to bottom) length of the matrix
 * Return: unsuccessful
 */

void free_grid(char **grid, int height)
{
	int n;

	for (n = 0; n < height; n++)
	{
		free(grid[n]);
	}
	free(grid);
}
