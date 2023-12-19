#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 1024
/**
 * main - entry point
 *
 * Return: Always 0
 */
char *readline(int *fd, char *buffer)
{
	*fd = read(STDIN_FILENO, buffer, BUFFER_SIZE);

	if (*fd == -1)
		return (NULL);

	return (buffer);
}
char cl_env_write(char sign)
{
	char *cl_env = malloc(sizeof(char) * 3);
	int fd;

	if (cl_env == NULL)
		return (1);

	cl_env[0] = sign;
	cl_env[1] = 32;
	cl_env[2] = 0;

	fd = write(STDOUT_FILENO, cl_env, 3);

	if (fd == -1)
		return (1);
	return (0);
}

int main(void)
{
	char error_handler, *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	int *fd, fw;

	error_handler = cl_env_write('$');
	if (error_handler)
		exit(98);

	if (readline(fd, buffer) == NULL)
		exit(99);

	fw = write(STDOUT_FILENO, buffer, *fd);

	if (fw == -1)
		exit(100);
	return (0);
}
