#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024
/**
 * main - PID
 *
 * Return: Always 0.
 * Exit codes: !open - 98, !read - 99, !write - 100
 */
int main(void)
{
	int fo = open("/proc/sys/kernel/pid_max", O_RDONLY), fr, fw;
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (!buffer)
		printf("Malloc error\n"), exit(97);

	if (fo == -1)
		printf("FILE cannot be opened\n"), exit(98);

	fr = read(fo, buffer, BUFFER_SIZE);

	if (fr == -1)
		printf("FILE cannot be read\n"), exit(99);

	fw = write(STDOUT_FILENO, buffer, fr);

	if (fw == -1)
		printf("FILE cannot be outputed\n"), exit(100);

	return (0);
}
