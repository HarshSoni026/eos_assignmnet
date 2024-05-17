#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int arr[2];

void sigint_handler(int sig) {
	close(arr[1]);
	close(arr[0]);
	printf("Handler impliment\n");
	_exit(0);
}

int main(){
	struct sigaction sa;
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGINT, &sa, NULL);

	char ch = 'A';
	int ret;
	ret = pipe(arr);

	int count = 0;
	

	while(1) {
		write(arr[1], &ch, 1);
		count++;
		printf("bytes written: %d\n", count);
	}	
}
