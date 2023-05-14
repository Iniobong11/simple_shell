#include "shell.h"

/**
 * main - entry point for the program
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 * @envp: array of environment variable strings
 *
 * Description: This program checks the number of command-line arguments and
 *              calls different functions depending on the number of arguments.
 *              If no arguments are passed, it calls the _noargv function.
 *              If one argument is passed, it calls the _yesargv function.
 *              Otherwise, it prints an error message to standard output.
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *envp[])
{
	/* Check if no arguments were passed */
	if (argc == 1)
	{
		_noargv(argv, envp);
	}
	/* Check if one argument was passed */
	else if (argc == 2)
	{
		_yesargv(argv, envp);
	}
	/* Handle other cases */
	else
	{
		/* Write error message to standard output */
		write(STDOUT_FILENO, "NO ADMITTED AMOUNT OF ARGUMENTS\n", 31);
	}

	/* Return success */
	return (0);
}

