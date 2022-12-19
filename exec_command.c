#include "main.h"

/**
*exec_command - execute a command in the shell
*@tokens: an array of character pointers containing the tokens
*@envp: environment variables from the calling function
*Return: void
*/

int exec_command(char **tokens, char **envp)
{
	pid_t child_pid;
	int status, result;
	char *command = NULL, *actual_command = NULL;

	if (tokens[0] == NULL)
	{
		return (0);
	}
	command = tokens[0];
	actual_command = get_location(command);
	if (strcmp(command, "exit") == 0)
		exit(0);
	else if (strcmp(command, "env") == 0)
	{
		env_command();
		return (0);
	}
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			result = execve(actual_command, tokens, envp);
			if (result == -1)
			{
				perror("Error");
			} exit(result);
		}
		else if (child_pid > 0)
		{
			wait(&status);
			return (WEXITSTATUS(status));
		}
		else
		{
			perror("Error");
			return (-1);
		}
	} return (0);
}
