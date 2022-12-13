#include "main.h"

/**
*token_string - separate a string into different tokens
*@args: string to be tokenized
*Return: void
*/

char **tokenize_string(char *str, size_t num)
{
	char *str_copy;
	char *token;
	char **tokens;
	const char *delim = " \n";
	int num_tokens = 0;
	int i = 0;

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
		return(NULL);
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
