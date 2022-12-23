 #include "main.h"

/**
*main - write a unix command line interpreter
*@ac: argument count
*@av: argument vector
*Return: 0 if successful or Error if otherwise
*/

int main(int ac __attribute__((unused)), char *av[] __attribute__((unused)))
{
	char *lineptr;
	size_t num = 0;
	ssize_t num_chars = 0;
	int int_mode, result, count = 0;
	char **toks;

	/*signal(SIGINT, sigint_handler);*/

	while (1)
	{
		count++;
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			/*write(STDOUT_FILENO, "($) ", 4);*/
			printf("($) ");
		}
		num_chars = getline(&lineptr, &num, stdin);
		if (num_chars == -1)
		{
			printf("\n");
			return (-1);
		}
		toks = tokenize_string(lineptr, num_chars);

		result = exec_command(toks, av, count);
	}
	return (result);
}
