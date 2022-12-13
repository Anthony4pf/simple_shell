#include "main.h"

/**
*tokenize_string - separate a string into different tokens
*@str: string to be tokenized from the terminal
*@num: number of characters read from the terminal
*Return: array of tokens
*/

char **tokenize_string(char *str, ssize_t num)
{
	char *str_copy, *token;
	char **tokens;
	const char *delim = " \n";
	int num_tokens = 0, i = 0;

	str_copy = malloc(sizeof(char) * num);
	if (str_copy == NULL)
	{
		perror("Error");
		return (NULL);
	}
	strcpy(str_copy, str);
	token = strtok(str, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	tokens = malloc(sizeof(char *) * num_tokens);
	if (tokens == NULL)
	{
		perror("Error");
		return (NULL);
	}
	token = strtok(str_copy, delim);
	while (token != NULL)
	{
		tokens[i] = malloc(sizeof(char) * strlen(token));
		strcpy(tokens[i], token);

		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
