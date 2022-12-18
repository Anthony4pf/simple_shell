#include "main.h"

/**
*exec_command - execute a command in the shell
*@tokens: an array of character pointers containing the tokens
*@envp: environment variables from the calling function
*Return: void
*/

void exec_command(char **tokens, char **envp)
{
	pid_t child_pid;
	int status;
	char *command = NULL, *actual_command = NULL;

	if (tokens != NULL)
	{
		command = tokens[0];
		actual_command = get_location(command);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
		}
		else if (child_pid == 0)
		{
			if (execve(actual_command, tokens, envp) == -1)
			{
				perror("Error");
			}
		}
		else
		{
			wait(&status);
		}
	}
}
