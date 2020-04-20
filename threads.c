/**
 * This program forks a separate process using the fork()/exec() system calls.
 *
 * Figure 3.08
 *
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>

struct arg{
	int id;
};

void* forkPThread(void* arg){
	struct arg* argument = (struct arg*) arg;

	int id = argument->id;
	if (id < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed\n");

	}
	else if (id == 0) { /* child process */
		printf("I am the child %d\n", id);
		execlp("/bin/ls","ls",NULL);
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		printf("I am the parent %d\n",id);

	}
	return arg;
}

int main()
{
	pthread_t threads[2];

	struct arg args[2];

	struct arg *arg1 = &args[0];
	arg1->id = 0;
	struct arg *arg2 = &args[1];
	arg2->id = getpid();

	pthread_create(&threads[0], NULL, forkPThread, arg1);
	pthread_create(&threads[1], NULL, forkPThread, arg2);


	pthread_join(threads[0], NULL);
	printf("Child Complete\n"); //doesn't print I don't know why
	pthread_join(threads[1], NULL);


}
