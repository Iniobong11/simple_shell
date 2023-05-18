#include "shell.h"

/**
 * currentstatus - Get or set the current status value.
 *
 * @status: Pointer to an integer representing the new status value.
 *
 * Return: The current value of the status.
 */
int currentstatus(int *status)
{
	static int actual;

	if (status)
		actual = *status;
	return (actual);
}

/*
 * _frk - Create a child process using fork() and execute a command.
 *
 * @p: The array of command arguments.
 * @l: The first argument of the command.
 * @a: The number of arguments.
 * @L: The line number.
 * @v: The array of environment variables.
 * @e: The number of environment variables.
 * @m: The array of modified environment variables.
 * @f: The filename.
 */
void _frk(char **p, char * 1, int a, int L, char **v, int e, char **m, char *f)
{
	pid_t child_pid;
	int ty = 0, status, exist, execute;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(127);
	}
	if (child_pid == 0)
	{
		if (execve(p[0], p, m) == -1)
		{
			exist = access((const char *) p[0], F_OK);
			execute = access((const char *) p[0], X_OK);
			if (exist == 0 && execute == -1)
			{
				_put_err(p, L, 4, v);
				free(f), free(1);
				free_grid(p, a), free_grid(m, e);
				exit(126);
			}
			else
			{
				_put_err(p, L, 3, v);
			}
			free(f), free(1);
			free_grid(p, a), free_grid(m, e);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			ty = WEXITSTATUS(status);
			currentstatus(&ty);
		}
	}
}
