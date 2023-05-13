#include "shell.h"
/**
 * main - Entry point for the program
 * @argc: The number of command line arguments
 * @argv: An array of strings containing the command line arguments
 * @envp: An array of strings containing the environment variables
 *
 * Return: Always 0 (Success)
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

