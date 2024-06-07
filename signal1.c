#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void handler(int signum)
{
	printf("SIGUSR1 received\n");
}

int main(void)
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	
	if ((sigaction(SIGUSR1, &sa, NULL)) == -1){
		perror("sigaction");
		exit(1);
	}
	
	while (1){
		sleep(0.01);
	}
	
	return 0;
}
