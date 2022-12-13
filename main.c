#include "main.h"

/**
*main - write a unix command line interpreter
*@argc: argument count
*@argv: argument vector
*@envp: environmental variables
*Return: 0 if successful or Error if otherwise
*/

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char **envp)
{
	char *lineptr;
	size_t num = 0;
	ssize_t num_chars = 0;
	int int_mode;
	char **toks;

	while (1)
	{
		int_mode = isatty(STDIN_FILENO);

		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "($) ", 4);
		}

		num_chars = getline(&lineptr, &num, stdin);

		if (num_chars == -1)
		{
			return (-1);
		}
		toks = tokenize_string(lineptr, num_chars);

		exec_command(toks, envp);
	}

	free(lineptr);
	free(toks);
	return (0);
}
