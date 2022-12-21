#include "main.h"

/**
* *_strcpy - copy the string pointed to by src to dest
*@src: first pointer
*@dest: second pointer
*Return: the pointer copied to dest
*/

char *_strcpy(char *dest, char *src)
{
	int i, length;

	for (length = 0; src[length] != '\0'; length++)
	{

	}

	for (i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
*_puts - Print a string to stdout
*@str: string to be printed to stdout
*Return: Void Always
*/

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	_putchar ('\n');
}

/**
*_strlen - Return the length of a string
*@s: string to be counted
*Return: Length of the entered string
*/

int _strlen(char *s)
{
	int i;
	int length = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}

	return (length);
}

/**
*_strdup - returns a pointer to a newly allocated memory
*@str: string to be copied
*Return: pointer
*/

char *_strdup(char *str)
{
	unsigned int i, j;
	char *string;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	;

	string = (char *)malloc(sizeof(char) * i + 1);

	if (string == NULL)
		return (NULL);

	for (j = 0; j <= i; j++)
		string[j] = str[j];

	return (string);
}

/**
*_strcat - Concatenates two strings
*@dest: first string
*@src: second string
*Return: Pointer to Dest
*/

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i]; i++)
	{
	}

	for (j = 0; src[j]; j++, i++)
	{
		dest[i] = src[j];
	}

	dest[i] = '\0';

	return (dest);
}
