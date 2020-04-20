#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>


int main(int argc, char *argv[])
{
	printf("Parent thread beginning execution\n");

	pid_t pid;


	pid = fork();
	printf("After first fork, thread %d is runnning\n", getpid());
	pid = fork();
	printf("After second fork, thread %d is runnning\n", getpid());
	pid = fork();
	printf("After third fork, thread %d is runnning\n", getpid());


}
