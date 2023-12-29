#include "shell.h"
#include "error.h"
#include "func_proto.h"

#define ARGC 100
/**
 * token_str - divides string to tokens
 * @query: given query
 * Return: matrix of strings (for argv)
 */
char **token_str(char *query)
{
	char *token, **tokens;
	int i = 0;

	tokens = malloc(sizeof(char *) * ARGC);
	if (tokens == NULL)
	{
		free(query);
		perror(ALLOC_ERR);
		exit(98);
	}
	token = strtok(query, " \t\n");
	while (token)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
