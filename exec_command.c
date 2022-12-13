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

	if (tokens != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
		}
		else if (child_pid == 0)
		{
			if (execve(tokens[0], tokens, envp) == -1)
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
