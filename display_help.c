#include "shell.h"

/**
 * read_help - prints and read builtins text files to POSIX stdout
 * @m: ccopy environmental variables
 * Return: no of characters to write, or o.
 */

ssize_t read_help(char **m)
{
	int ik, m, n;
	char *buf;
	char helpfiles[] =
"/simple_shell/_helpfiles/help_all.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	ik = open(helpdir, O_RDONLY);
	if (ik == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	m - read(ik, buf, letters);
	if (m == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	n = write(STDOUT_FILENO, buf, m);
	if (n == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(ik);
	free(helpdir);
	free(buf);
	return (m);
}

/**
 * read_cdhelp - reads text file and print to POSIX stdout
 * @m: environmental variables
 * Return: no of aphabets to write or 0.
 */

ssize_t read_cdhelp(char **m)
{
	int ik, m, n;
	char *buf;
	char helpfiles[] =
"/simple_shell/_helpfiles/help_cd.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == Null)
		return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	ik = open(helpdir, O_RDONLY);
	if (ik == -1)
	{
		free(helpdir);
		free(buf);
		refurn(0);
	}
	m = read(ik, buf, letters);
	if (m == -1)
	{
	free(helpdir);
	free(buf);
	return (0);
	}
	n = write(STDOUT_FILENO, buf, m);
	if (n == -1)
	{
	free(helpdir);
	free(buf);
	return (0);
	}
	close(ik);
	free(helpdir);
	free(buf);
	return (m);
	}
/**
* read_exithelp - reads and prints exit text file to POSIX stdout
* @m: environment variables
* Return: number of alphabets to write, or 0.
*/
ssize_t read_exithelp(char **m)
{
	int ik, m, n;
	char *buf;
	char helpfiles[] =
"/simple_shell/_helpfiles/help_exit.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
	return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	ik = open(helpdir, O_RDONLY);
	if (ik == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	m = read(ik, buf, letters);
	if (m == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	n = write(STDOUT_FILENO, buf, m);
	if (n == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(ik);
	free(helpdir);
	free(buf);
	return (m);
}
/**
* read_helphelp - helps in reading text file and print
* * @m: environmental copy of variables
* Return: number of alphabets to  write, or 0.
*/
ssize_t read_helphelp(char **m)
{
	int ik, m, n;
	char *buf;
	char helpfiles[] =
"/simple_shell/_helpfiles/help_help.txt";
	char *home, *helpdir;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
	return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	ik = open(helpdir, O_RDONLY);
	if (ik == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	m = read(ik, buf, letters);
	if (m == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	n = write(STDOUT_FILENO, buf, m);
	if (n == -1)
	{
		free(helpdir);
		free(buf);
		return (0);
	}
	close(ik);
	free(helpdir);
	free(buf);
	return (m);
}
