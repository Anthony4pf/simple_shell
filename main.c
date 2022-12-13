#include "main.h"

/**
*main - write a unix command line interpreter
*@argc: argument count
*@argv: argument vector
*Return: 0 if successful or Error if otherwise
*/

int main(int argc, char *argv[], char **envp)
{
	char *lineptr;
	size_t num = 0, num_chars = 0;
	int int_mode;
	char **toks;
	pid_t pid;

	while (1)
	{
		int_mode = isatty(STDIN_FILENO);
		
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "($) ", 4);
		}
		
		if ((num_chars = getline(&lineptr, &num, stdin) == -1))
		{
			write(STDOUT_FILENO, "\n", 2);
			return(-1);
		}
		toks = tokenize_string(lineptr, num_chars);
		
		exec_command(toks, envp);
	}

	free(lineptr);
	free(toks);	
	return (0);
}
