#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	sigset_t set;
	
	if ((sigemptyset(&set)) == -1){
		perror("sigemptyset");
		exit(1);
	}
	
	if ((sigaddset(&set, SIGINT)) == -1){
		perror("sigaddset");
		exit(1);
	}
	
	if ((sigprocmask(SIG_BLOCK, &set, NULL)) == -1){
		perror("sigprocmask");
		exit(1);
	}
	
	while (1){
		printf("the process is still running\n");
		sleep(1);
	}
	
	return 0;
}
