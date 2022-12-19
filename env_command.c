#include "main.h"

/**
*env_command - print environmental variables
*Return: void
*/

void env_command(void)
{
	char **envp;

	envp = environ;

	while (*envp != NULL)
	{
		printf("%s\n", *envp);
		envp++;
	}
}
