#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t ppid, pid;

	pid = getpid();
	ppid = getppid();
	printf("PPID: %u\nPID: %u\n", ppid, pid);
	return (0);
}
