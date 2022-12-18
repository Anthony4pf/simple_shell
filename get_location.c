#include "main.h"

/**
 * get_location - a pointer to the location of a file
 * @command: the char whose location we are to find
 * Return: command
 */




char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_lenght, directory_lenght;
	struct stat buf;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_lenght = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_lenght = strlen(path_token);

			file_path = malloc(command_lenght + directory_lenght + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buf) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);

		if (stat(command, &buf) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
