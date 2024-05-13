#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 

int main()
{
	int ret,s,i;
	i=1;
	while(1){
		ret = fork();
		if(ret==0){
		_exit(0);
		}
		else if(ret == -1)
			break;
		else{
			i++;
			}
		}
		for(int j=1; j<=i; j++)
		wait(&s);

		printf("Max number of processes : %d\n", i);

	
return 0;
}
