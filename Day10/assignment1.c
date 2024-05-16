#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
	int pid,sig,ret;

	printf("Enter process ID : ");
	scanf("%d", &pid);

	printf("Enter signal number : ");
	scanf("%d", &sig);

	ret = kill(pid,sig);

	if (ret == 0)
		printf("Signal sent successfully!\n");

	else 
		printf("Signal not sent!\n");

	if ( ret == -1)
		perror("kill");

	return 0;
}
