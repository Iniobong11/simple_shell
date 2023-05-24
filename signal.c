#include "shell.h"
/**
 * _signal - SIGINT signal handle
 * @s: catch signal
 */
void _signal(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
