#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	sigset_t set;
	int sig;
	
	if ((sigemptyset(&set)) == -1){
		perror("sigemptyset");
		exit(1);
	}
	
	if ((sigaddset(&set, SIGUSR1)) == -1){
		perror("sigaddset");
		exit(1);
	}
	
	while (1){
		if ((sigwait(&set, &sig)) == -1){
			perror("sigwait");
			exit(1);
		}
	}
	
	return 0;
}
