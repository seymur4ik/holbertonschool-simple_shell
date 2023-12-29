#include "shell.h"
#include "func_proto.h"
#include "error.h"

/**
 * write_ps - writes prompt string
 * @prompt_string: prompt string to write
 * Return: Return value of write
 */
int write_ps(char *prompt_string)
{
	return (write(STDOUT_FILENO, prompt_string, strlen(prompt_string)));
}

/**
 * main - entry point to shell
 * @argc: count of arguments
 * @argv: array of arguments
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	size_t buf_size = BUFFER_SIZE;
	int tty_ret = 0, ps_ret;
	char *prompt_string = "#cisfun$ ", *query = malloc(sizeof(char) * buf_size);

	(void)argc, (void)argv;
	while (true)
	{
		tty_ret = isatty(STDIN_FILENO);

		if (query == NULL)
		{
			perror(ALLOC_ERR);
			return (1);
		}

		if (tty_ret == 1)
			ps_ret = write_ps(prompt_string);
		else
			errno = 0;

		if (ps_ret == -1)
		{
			free(query), perror(PS_ERR);
			return (1);
		}

		if (get_query(&query, &buf_size, &tty_ret) == 0)
			return (1);
		/*command_path = &query, command_argv = (char *[]){*command_path, NULL};*/

		if (command_execution(&query) == 0)
			return (1);
	}

	free(query);
	return (0);
}
