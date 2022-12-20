#include "main.h"

/**
*exec_command - execute a command in the shell
*@tokens: an array of character pointers containing the tokens
*@av: argument vector from the calling function
*@count: counter for shell prompt
*Return: void
*/

int exec_command(char **tokens, char **av, int count)
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
			result = execve(actual_command, tokens, environ);
			if (result == -1)
			{
				printf("%s: %d: %s: not found\n", av[0], count, command);
				exit(127);
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
