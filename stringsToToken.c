#include "shell.h"

/**
 * nbr_spaces - return the number of occurrence of a string
 *
 * @s: string to checkk
 *
 * Return: an integer
 */
unsigned int nbr_spaces(char *s)
{
	int i, cmpt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			cmpt++;
	}
	return (cmpt);
}

/**
 * stringToTokens - split a sentence into multiple words.
 *
 * @str: The string passed as argument
 *
 * Return: the tokens
 */
char **stringToTokens(char *str)
{
	int i = 0;
	const char separator[] = " ";
	int spaces = nbr_spaces(str);
	char **tokens = malloc(sizeof(char *) * (spaces + 1));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}
	token = strok(str, separator);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strok(NULL, separator);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
