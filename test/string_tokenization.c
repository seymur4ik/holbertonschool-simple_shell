#include "shell.h"
#include "error.h"
#include "func_proto.h"

#define ARGC 100
/**
 * token_str - divides string to tokens
 * @query: given query
 * @delim: delimiter
 * Return: matrix of strings (for argv)
 */
char **token_str(char *query, const char *delim)
{
	int argc = 0;
	unsigned long int query_len = strlen(query), token_length;
	char *str = strdup(query), **argv, *token;

	if (str == NULL)
		return (NULL);

	argv = (char **)malloc(sizeof(char *) * 20);

	if (argv == NULL)
		return (NULL);

	token = strtok(str, delim);
	while (token != NULL && argc < 20)
	{
		token_length = strlen(token);
		argv[argc] = (char *)malloc(sizeof(char) * (token_length + 1));

		if (argv[argc] == NULL)
		{
			for (; argc > 0; argc--)
				free(argv[argc]);
			free(argv);
			return (NULL);
		}
		strcpy(argv[argc], token), token = strtok(NULL, delim);
		argc++;
	}
	for (int i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	free(str);
	return (argv);
}
