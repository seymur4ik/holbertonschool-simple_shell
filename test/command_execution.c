#include "shell.h"
#include "error.h"
#include "func_proto.h"

/**
 * command_execution - creates a child process to execute a command
 * @query: message from getline
 * Return: 0 is error
 */
int command_execution(char **query)
{
	int child_id, exec_ret, wait_ret;
	char **command_argv = malloc(sizeof(char *) * 12);

	if (command_argv == NULL)
	{
		free(*query);
		return (0);
	}
	command_argv[0] = *query;
	command_argv[1] = NULL;
/*
	command_argv = token_str(*query, " ");
	if (command_argv == NULL)
		return (0);
	command_argv = token_str(*query, "\t");
	if (command_argv == NULL)
		return (0);

	for (int i = 0; i < 3; i++)
		if (command_argv[i] != NULL)
			printf("%s\n", command_argv[i]);
*/	child_id = fork();

	if (child_id == -1)
	{
		free(*query), free(command_argv), perror(PROC_CREAT_ERR);
		return (0);
	}
	else if (child_id == 0)
	{
		exec_ret = execve(command_argv[0], command_argv, NULL);

		if (exec_ret == -1)
		{
			free(*query), free(command_argv), perror(PROC_EXEC_ERR);
			return (0);
		}
	}
	else
	{
		wait_ret = wait(NULL);
		if (wait_ret == -1)
		{
			free(*query), free(command_argv), perror(PROC_WAIT_ERR);
			return (0);
		}
	}
	free(command_argv);
	return (1);
}
