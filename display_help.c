#include "shell.h"

/**
 * read_help - prints and read builtins text files to POSIX stdout
 * @m: ccopy environmental variables
 * Return: no of characters to write, or o.
 */

ssize_t read_help(char **m)
{       
        int fd, r, w;
        char *buf;
        char helpfiles[] =
"/simple_shell/_helpfiles/help_all.txt";
        char *home, *helpdir;
        size_t letters = 1024;
        buf = malloc((sizeof(char) *letters + 1));
        if (buf == NULL)
                return (0);
        home = _gethome(m);
        helpdir = str_concat(home, helpfiles);
        fd = open(helpdir, O_RDONLY);
        if (fd == -1)
        {       
                free(helpdir);
		free(buf);
		return (0);
	}
        r - read(fd, buf, letters);
        if (r == -1)
        {
                free(helpdir);
                free(buf);
                return (0);
        }
        w = write(STDOUT_FILENO, buf, r);
        if (w == -1)
        {
                free(helpdir);
                free(buf);
		return (0);
	}
	close(fd);
	free(helpdir);
	free(buf);
	return(r);
}

/**
 * read_cdhelp - reads text file and print to POSIX stdout
 * @m: environmental variables
 * Return: no of aphabets to write or 0.
 */

ssize_t read_cdhelp(char **m)
{
	int fd, r, w;
	char *buf;
	char helpfiles[] =
"/simple_shell/_helpfiles/help_cd.txt";
	char *home, *helpdir;
	size_t letters = 1024;
	buf = malloc((sizeof(char) *letters + 1));
	if (buf == Null)
		return (0);
	home = _gethome(m);
	helpdir = str_concat(home, helpfiles);
	fd = open(helpdir, O_RDONLY);
	if (fd == -1)
	{
		free(helpdir);
		free(buf);
		refurn (0);
	}
