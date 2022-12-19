#include "main.h"

/**
*main - write a unix command line interpreter
*@ac: argument count
*@av: argument vector
*@envp: environmental variables
*Return: 0 if successful or Error if otherwise
*/

int main(int ac __attribute__((unused)), char *av[] __attribute__((unused)),
char **envp)
{
	char *lineptr;
	size_t num = 0;
	ssize_t num_chars = 0;
	int int_mode;
	char **toks;
	int result, i = 0;

	while (1)
	{
		signal(SIGINT, SIG_IGN);
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "($) ", 4);
		}
		num_chars = getline(&lineptr, &num, stdin);
		if (num_chars == -1)
		{
			printf("\n");
			return (-1);
		}
		toks = tokenize_string(lineptr, num_chars);

		result = exec_command(toks, envp);
	}
	return (0);
}
