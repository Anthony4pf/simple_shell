#include "main.h"

/**
*exec_command - execute a command in the shell
*@tokens: an array of character pointers containing the tokens
*@av: argument vector from the calling function
*@count: counter for shell prompt
*Return: void
*/

int exec_command(char **tokens, char **av __attribute__((unused)), int count __attribute__((unused)))
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
	if (_strcmp(command, "exit") == 0)
		exit(0);
	else if (_strcmp(command, "env") == 0)
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
				/*fprintf(stderr, "%s: %d: %s: not found\n", av[0], count, command);*/
				perror("Error: command not found");
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
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
	} return (0);
}
